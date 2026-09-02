cmake_minimum_required(VERSION 3.20)
project(ESsentialX VERSION 0.1.0 LANGUAGES CXX)

# 1. Hier C++20 für deine eigene Bibliothek aktivieren
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build a static library from src/file.cpp
add_library(ESsentialX STATIC
        src/file.cpp
        src/math.cpp
        src/text.cpp
        src/algo.cpp
        src/worldGen.cpp
)

# WICHTIG: Damit add_subdirectory mit ESsentialX::esx verlinken kann!
add_library(ESsentialX::esx ALIAS ESsentialX)

# Public include dir so consumers can do: #include <esx/file.hpp>
target_include_directories(ESsentialX
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# 2. Hier auf cxx_std_20 ändern, damit auch die Benutzer deiner Lib automatisch C++20 nutzen
target_compile_features(ESsentialX PUBLIC cxx_std_20)

# Export name so exported target is ESsentialX::esx (matches small name "esx")
set_target_properties(ESsentialX PROPERTIES EXPORT_NAME esx)

# Install rules (optional, useful to allow find_package after install)
include(CMakePackageConfigHelpers)

install(TARGETS ESsentialX
        EXPORT ESsentialXTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT ESsentialXTargets
        FILE ESsentialXTargets.cmake
        NAMESPACE ESsentialX::
        DESTINATION lib/cmake/ESsentialX
)

# Generate simple config files for find_package when installed
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/ESsentialXConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

# 3. Kleiner Fix für korrekte Pfade bei der Installation
include(GNUInstallDirs)

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ESsentialXConfig.cmake"
        "@PACKAGE_INIT@\ninclude(\"\${CMAKE_CURRENT_LIST_DIR}/ESsentialXTargets.cmake\")\n")

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/ESsentialXConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ESsentialXConfigVersion.cmake"
        DESTINATION lib/cmake/ESsentialX
)