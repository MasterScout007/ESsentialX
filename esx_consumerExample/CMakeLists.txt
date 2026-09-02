cmake_minimum_required(VERSION 3.20)
project(esx_consumerExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ESX_CONFIG_DIR "C:/Users/sysadmin/CLionProjects/ESsentialX/cmake")

message(STATUS "Using ESsentialX config from: ${ESX_CONFIG_DIR}")

find_package(ESsentialX REQUIRED PATHS ${ESX_CONFIG_DIR} NO_DEFAULT_PATH)

add_executable(esx_consumerExample main.cpp)
target_link_libraries(esx_consumerExample PRIVATE ESsentialX::esx)