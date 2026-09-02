#include "esx/file.hpp"

#include <fstream>
#include <cstdio>     // std::remove
#include <iterator>
#include <string>
#include <vector>


namespace esx::file {
    // writeTextFile: sehr simple Implementierung
    bool writeTextFile(const std::string& path, const std::string& content) {
        std::ofstream ofs(path, std::ios::binary | std::ios::trunc);
        if (!ofs) {
            return false;
        }
        ofs << content;
        return static_cast<bool>(ofs);
    }

    // readTextFile: liest ganze Datei und gibt String zurück
    std::string readTextFile(const std::string& path) {
        std::ifstream ifs(path, std::ios::binary);
        if (!ifs) {
            return std::string{};
        }
        std::string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        return content;
    }

    // deleteFile: benutzt std::remove (C API), gibt true bei Erfolg
    bool deleteFile(const std::string& path) {
        int res = std::remove(path.c_str());
        return (res == 0);
    }

    // Automatisches Einlesen einer Datei in ein Vector von Strings
    std::vector<std::string> readTextFileLines(const std::string& path) {
        std::ifstream file(path);
        std::vector<std::string> lines;
        std::string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    // readTextFileLines: splittet den Text an '\n' und entfernt optional '\r'
    std::vector<std::string> Com_readTextFileLines(const std::string& path) {
        std::string content = readTextFile(path);
        std::vector<std::string> lines;
        if (content.empty()) {
            // Entweder leere Datei oder Fehler beim Lesen.
            return lines;
        }

        std::string current;
        current.reserve(128);
        for (size_t i = 0; i < content.size(); ++i) {
            char c = content[i];
            if (c == '\n') {
                // Entferne optionales '\r' am Ende
                if (!current.empty() && current.back() == '\r') current.pop_back();
                lines.push_back(current);
                current.clear();
            }
            else {
                current.push_back(c);
            }
        }
        // letzte Zeile (falls kein abschließendes '\n')
        if (!current.empty() || (!content.empty() && content.back() == '\n')) {
            if (!current.empty() && current.back() == '\r') current.pop_back();
            lines.push_back(current);
        }
        return lines;
    }

    // writeTextFileLines: join mit '\n' zwischen den Einträgen (keine extra Zeile am Ende)
    bool writeTextFileLines(const std::string& path, const std::vector<std::string>& lines) {
        std::string joined;
        if (!lines.empty()) {
            size_t approx = 0;
            for (const auto& s : lines) approx += s.size() + 1;
            joined.reserve(approx);

            for (size_t i = 0; i < lines.size(); ++i) {
                joined += lines[i];
                if (i + 1 < lines.size()) joined.push_back('\n');
            }
        }
        else {
            joined.clear();
        }
        return writeTextFile(path, joined);
    }
} // namespace esx::file
