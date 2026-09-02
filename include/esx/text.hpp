//
// Created by sysadmin on 07.06.2026.
//

#ifndef ESSENTIALX_TEXT_HPP
#define ESSENTIALX_TEXT_HPP
#include <string>
#include <vector>


namespace esx::text {
    // Sucht ein Zeichen (als String übergeben) im Text und gibt den Index zurück.
    // Index beginnt bei 0. Falls nicht gefunden oder Such-String leer: -1.
    int findChar(const std::string& text, const std::string& ch);

    //Teilt einen String an mehren Indexen. Es wird jeweils der 1. Idx von einem Abschnitt angegeben.
    std::vector<std::string> split(const std::string& text, const std::vector<int>& splittIdx);

    //Teilt einen String an einem Index. Es wird der 1. Idx vom 2. Abschnitt angegeben.
    std::vector<std::string> split(const std::string& text, int splittIdx);
}


#endif
