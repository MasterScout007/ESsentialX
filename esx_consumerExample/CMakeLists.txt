cmake_minimum_required(VERSION 3.20)
project(esx_consumerExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. ESsentialX aus dem Nachbarordner (~/ESsentialX) einbinden
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../ESsentialX" ESsentialX_build)

# 2. Executable erstellen
add_executable(esx_consumerExample main.cpp)

# 3. Verlinken (funktioniert jetzt sowohl mit ESsentialX::esx als auch mit ESsentialX)
target_link_libraries(esx_consumerExample PRIVATE ESsentialX::esx)