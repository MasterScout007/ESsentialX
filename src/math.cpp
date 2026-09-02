#include "esx/math.hpp"

#include <fstream>
#include <span>
#include <iterator>
#include <string>
#include <vector>
#include <cmath>


namespace esx::math {
    // Neue Funktion für deine Library:
    std::vector<float> convertToFloat(const std::vector<std::string>& inputTokens) {
        std::vector<float> floatNumbers;

        floatNumbers.reserve(inputTokens.size());

        for (const std::string& token : inputTokens) {
            floatNumbers.push_back(std::stof(token));
        }

        return floatNumbers;
    }

    int pos(const int number) {
        return (number < 0) ? -number : number;
    }

    float pos(const float number) {
        return (number < 0.0f) ? -number : number;
    }

    double pos(const double number) {
        return (number < 0.0f) ? -number : number;
    }

    int arraySum(const std::span<const int> numbers) {
        int sum = 0;
        for (const int numb : numbers) {
            sum += numb;
        }
        return sum;
    }

    float arraySum(const std::span<const float> numbers) {
        float sum = 0.0f;
        for (const float numb : numbers) {
            sum += numb;
        }
        return sum;
    }

    int arrayAverage(const std::span<const int> numbers) {
        const int sum = arraySum(numbers);

        if (numbers.size() <= 0) return 0;

        return sum / numbers.size();
    }

    float arrayAverage(const std::span<const float> numbers) {
        const float sum = arraySum(numbers);

        if (numbers.size() <= 0.0f) return 0.0f;

        return sum / numbers.size();
    }

    float clamp(float val, float min, float max) {
        if (max < min) return val; // error
        if (val < min) return min;
        if (val > max) return max;

        return val;
    }

    float percentage(const float val, const float min, const float max) {
        const float range = max - min;

        if (range == 0.0f) return 0.0f;

        const float percentage = (val - min) / range;

        return percentage;
    }

    int round(const float number) {
        return std::lround(number);
    }
    int round(const double number) {
        return std::lround(number);
    }

    int roundDown(const float number) {
        return static_cast<int>(std::floor(number));
    }
    int roundDown(const double number) {
        return static_cast<int>(std::floor(number));
    }


    int directionToZero(const int number) {
        if (number < 0) return -1;
        if (number > 0) return 1;

        else return 0;
    }

    int directionToZero(const float number) {
        if (number < 0) return -1;
        if (number > 0) return 1;

        else return 0;
    }

    int directionToZero(const double number) {
        if (number < 0) return -1;
        if (number > 0) return 1;

        else return 0;
    }
}
