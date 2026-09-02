#include <random>
#include <algorithm>
#include <cmath>

#include "esx/worldGen.hpp"

namespace esx::worldGen {
    // Berechnet die neue Steigungsänderung (-100% bis +100%)
    float getNextSlopeChange(
        float currentHeight,
        float currentSlopePercent,
        const TerrainConfig& config,
        const GenerationWeights& weights
    ) {
        static std::random_device rd;
        static std::mt19937 generator(rd());

        // 1. Der reine Zufall (Normalverteilung um 0)
        std::normal_distribution<float> distribution(0.0f, weights.randomnessStdDev);
        float slopeChange = distribution(generator);

        // --- KRAFT 1: Tendenz zur Durchschnittshöhe (averageHeight) ---
        float heightDeviation = (config.averageHeight - currentHeight) / (config.maxHeight - config.minHeight);
        slopeChange += heightDeviation * weights.heightGravityStrength;

        // --- KRAFT 2: Natürlicher Schutz an Ober- und Untergrenze (Anti-Flach-System) ---
        // Oberseite: Je näher am Maximum, desto stärker der Druck nach unten
        float distanceToMax = config.maxHeight - currentHeight;
        if (distanceToMax < (config.maxHeight - config.averageHeight)) {
            float upperDanger = 1.0f - (distanceToMax / (config.maxHeight - config.averageHeight));
            slopeChange -= (upperDanger * upperDanger) * weights.boundaryPushStrength;
        }
        // Unterseite: Je näher am Minimum, desto stärker der Druck oben
        float distanceToMin = currentHeight - config.minHeight;
        if (distanceToMin < (config.averageHeight - config.minHeight)) {
            float lowerDanger = 1.0f - (distanceToMin / (config.averageHeight - config.minHeight));
            slopeChange += (lowerDanger * lowerDanger) * weights.boundaryPushStrength;
        }

        // --- KRAFT 3: Widerstand gegen extreme Steilheit (Nicht zu häufig steil) ---
        // Da wir kein extra Limit haben, nutzen wir die 100% als maximalen Bezugspunkt
        float slopeRatio = currentSlopePercent / 100.0f; // Bereich -1.0 bis +1.0
        slopeChange -= (slopeRatio * std::abs(slopeRatio)) * weights.slopeReturnStrength;

        return slopeChange;
    }
}
