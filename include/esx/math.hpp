//
// Created by sysadmin on 04.06.2026.
//

#include <span>

#ifndef ESSENTIALX_MATH_HPP
#define ESSENTIALX_MATH_HPP


namespace esx::math {
    // Gibt die Zahl positiv zurück
    int pos(int number);

    // Gibt die Zahl positiv zurück
    float pos(float number);

    // Gibt die Zahl positiv zurück
    double pos(double number);

    // Gibt die Summe aller Einträge eines Arrays zurück
    int arraySum(std::span<const int> numbers);

    // Gibt die Summe aller Einträge eines Arrays zurück
    float arraySum(std::span<const float> numbers);

    // Gibt den Durchschnitt eines Arrays zurück
    //int arrayAverage(std::span<const int> numbers); //average hasnt to be int

    // Gibt den Durchschnittswert eines Arrays zurück
    float arrayAverage(std::span<const float> numbers);

    //Gibt einen Wert innerhalb eines erlaubten Bereichs wieder
    float clamp(float val, float min, float max);

    //Gibt den Prozentwert wieder
    float percentage(float val, float min, float max);

    //NEW:

    //
    int round(float number);

    int round(double number);

    int roundDown(float number);

    int roundDown(double number);

    int directionToZero(int number);
    int directionToZero(double number);
    int directionToZero(float number);
}


#endif //ESSENTIALX_MATH_HPP
