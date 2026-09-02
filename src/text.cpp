//
// Created by sysadmin on 07.06.2026.
//

#include "esx/text.hpp"

#include <string>
#include <vector>


namespace esx::text {
    std::vector<std::string> split(const std::string& input, char delimiter) {
        std::vector<std::string> tokens;
        std::string currentToken = "";

        for (char ch : input) {
            if (ch == delimiter) {
                tokens.push_back(currentToken);

                currentToken = "";
            } else {
                currentToken += ch;
            }
        }

        tokens.push_back(currentToken);

        return tokens;
    }



    // findChar: sucht erstes Vorkommen des ersten Zeichens von ch im text
    int findChar(const std::string& text, const std::string& ch) {
        if (ch.empty()) return -1;
        char target = ch[0];
        for (size_t i = 0; i < text.size(); ++i) {
            if (text[i] == target) return static_cast<int>(i);
        }
        return -1;
    }

    std::vector<std::string> split(const std::string& text, const std::vector<int>& splittIdx) {
        std::vector<std::string> parts;
        parts.reserve(splittIdx.size());

        int lastIdx = 0;

        for (size_t i = 0; i < splittIdx.size(); ++i) {
            const int curr = splittIdx[i];

            if (curr <= 0 || curr <= lastIdx) {
                continue;
            }

            const int length = curr - lastIdx;

            parts.push_back(text.substr(lastIdx, length));

            lastIdx = curr;
        }

        if (lastIdx < text.length()) {
            parts.push_back(text.substr(lastIdx));
        }

        return parts;
    }

    std::vector<std::string> split(const std::string& text, const int splittIdx) {
        std::vector<int> splitt;
        splitt.push_back(splittIdx);

        return split(text, splitt);
    }
}
