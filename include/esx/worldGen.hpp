//
// Created by sysadmin on 14.06.2026.
//

#ifndef ESSENTIALX_WORLDGEN_HPP
#define ESSENTIALX_WORLDGEN_HPP

namespace esx::worldGen {
    // Deine primären Steuerungsparameter für die Welt
    struct TerrainConfig {
        float minHeight;
        float maxHeight;
        float averageHeight; // Die Wohlfühl-Höhe des Terrains
        float maxHeightChange; // Maximale Höhenänderung pro Block (entspricht 100% Steigung)
    };

    // Die "magischen Zahlen" für die mathematischen Kräfte
    struct GenerationWeights {
        float randomnessStdDev; // Grund-Zufälligkeit der Steigungsänderung (in %)
        float heightGravityStrength; // Wie stark zieht die averageHeight das Terrain an?
        float boundaryPushStrength; // Wie stark drücken Decke und Boden den Hang weg?
        float slopeReturnStrength; // Wie stark will die Welt zurück zu flachem Boden?
    };

    float getNextSlopeChange(
        float currentHeight,
        float currentSlopePercent,
        const TerrainConfig& config,
        const GenerationWeights& weights
    );
}

#endif //ESSENTIALX_WORLDGEN_HPP
