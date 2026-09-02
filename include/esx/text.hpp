//
// Created by sysadmin on 07.06.2026.
//

#ifndef ESSENTIALX_TEXT_HPP
#define ESSENTIALX_TEXT_HPP
#include <string>
#include <vector>


namespace esx::text {

    // Gibt einen Vektor aus Teilstrings (Tokens) zurück
    std::vector<std::string> split(const std::string& input, char delimiter);

    // Schneidet einen Teilbereich aus einem Vektor heraus (von startIndex bis vor endIndex)
    template <typename T>
    std::vector<T> slice(const std::vector<T>& inputVector, size_t startIndex, size_t endIndex) {
        std::vector<T> result;

        if (startIndex >= inputVector.size() || endIndex > inputVector.size() || startIndex > endIndex) {
            return result; // Gibt einen leeren Vektor zurück
        }

        result.reserve(endIndex - startIndex);

        for (size_t i = startIndex; i < endIndex; ++i) {
            result.push_back(inputVector[i]);
        }

        return result;
    }


    // Kombiniert zwei Vektoren des gleichen Typs zu einem einzigen Vektor
    template <typename T>
    std::vector<T> merge(const std::vector<T>& vector1, const std::vector<T>& vector2) {
        std::vector<T> result;

        // Speicherplatz für beide Vektoren auf einmal reservieren (sehr performant!)
        result.reserve(vector1.size() + vector2.size());

        // Die Elemente aus dem ersten Vektor hinzufügen
        for (const auto& item : vector1) {
            result.push_back(item);
        }

        // Die Elemente aus dem zweiten Vektor hinzufügen
        for (const auto& item : vector2) {
            result.push_back(item);
        }

        return result;
    }

    // Sucht ein Zeichen (als String übergeben) im Text und gibt den Index zurück.
    // Index beginnt bei 0. Falls nicht gefunden oder Such-String leer: -1.
    int findChar(const std::string& text, const std::string& ch);

    //Teilt einen String an mehren Indexen. Es wird jeweils der 1. Idx von einem Abschnitt angegeben.
    //std::vector<std::string> split(const std::string& text, const std::vector<int>& splittIdx);

    //Teilt einen String an einem Index. Es wird der 1. Idx vom 2. Abschnitt angegeben.
    //std::vector<std::string> split(const std::string& text, int splittIdx);
}


#endif
