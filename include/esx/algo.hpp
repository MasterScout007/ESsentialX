//
// Created by sysadmin on 07.06.2026.
//

#include <vector>

#ifndef ESSENTIALX_ALGO_HPP
#define ESSENTIALX_ALGO_HPP

namespace esx::algo {
    //gibt den Index des Eintrages mit dem größten Wert zurück
    int maxIndex(const std::vector<float>& vector);

    //gibt den Index des Eintrages mit dem größten Wert zurück
    int maxIndex(const std::vector<int>& vector);

    //gibt den Index des Eintrages mit dem kleinsten Wert zurück
    int minIndex(const std::vector<float>& vector);

    //gibt den Index des Eintrages mit dem kleinsten Wert zurück
    int minIndex(const std::vector<int>& vector);
}
#endif //ESSENTIALX_ALGO_HPP
