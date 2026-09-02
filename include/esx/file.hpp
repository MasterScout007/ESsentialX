#ifndef ESX_FILE_HPP
#define ESX_FILE_HPP

// Simple ESsentialX file utilities (text files)
// Very small, human-written, easy to read.
//
// Functions:
//  - bool writeTextFile(const std::string& path, const std::string& content);
//  - std::string readTextFile(const std::string& path);
//  - bool deleteFile(const std::string& path);
//
//  - int findChar(const std::string& text, const std::string& ch);
//  - std::vector<std::string> readTextFileLines(const std::string& path);
//  - bool writeTextFileLines(const std::string& path, const std::vector<std::string>& lines);

#include <string>
#include <vector>


namespace esx::file {
    // Schreibe den kompletten Text in eine Datei (überschreibt). Liefert true bei Erfolg, false bei Fehler.
    bool writeTextFile(const std::string& path, const std::string& content);

    // Lese die komplette Datei als String (inkl. Zeilenumbrüche). Bei Fehlern leerer String.
    std::string readTextFile(const std::string& path);

    // Lösche eine Datei. Liefert true bei Erfolg, false bei Fehler.
    bool deleteFile(const std::string& path);

    // Lese eine Text-Datei und gib die Zeilen als vector<string> zurück.
    // Zeilen werden anhand von '\n' getrennt; CR ('\r') am Zeilenende wird entfernt.
    // Bei Fehlern wird ein leerer vector zurückgegeben.
    std::vector<std::string> readTextFileLines(const std::string& path);

    // Schreibe ein Array von Zeilen in eine Datei. Zwischen jedem Eintrag wird genau ein '\n' gesetzt.
    // Wenn lines leer ist, entsteht eine leere Datei.
    bool writeTextFileLines(const std::string& path, const std::vector<std::string>& lines);
} // namespace esx::file


#endif // ESX_FILE_HPP
