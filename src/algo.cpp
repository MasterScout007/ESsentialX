//
// Created by sysadmin on 07.06.2026.
//

#include "esx/algo.hpp"


#include <iterator>
#include <string>
#include <vector>

namespace esx::algo {
    int maxIndex(const std::vector<float>& vector) {
        int highestIndex = 0;

        for (int i = 0; i < vector.size(); i++) {
            if (vector[i] > vector[highestIndex]) {
                highestIndex = i;
            }
        }
        return highestIndex;
    }

    int maxIndex(const std::vector<int>& vector) {
        int highestIndex = 0;

        for (int i = 0; i < vector.size(); i++) {
            if (vector[i] > vector[highestIndex]) {
                highestIndex = i;
            }
        }
        return highestIndex;
    }

    int minIndex(const std::vector<float>& vector) {
        int lowestIndex = 0;

        for (int i = 0; i < vector.size(); i++) {
            if (vector[i] < vector[lowestIndex]) {
                lowestIndex = i;
            }
        }
        return lowestIndex;
    }

    int minIndex(const std::vector<int>& vector) {
        int lowestIndex = 0;

        for (int i = 0; i < vector.size(); i++) {
            if (vector[i] < vector[lowestIndex]) {
                lowestIndex = i;
            }
        }
        return lowestIndex;
    }

}