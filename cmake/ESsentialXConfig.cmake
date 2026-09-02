# Minimal ESsentialXConfig.cmake (ready-to-use)
# This file assumes ESsentialXTargets.cmake is located in the same directory.

get_filename_component(_ESX_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include("${_ESX_CMAKE_DIR}/ESsentialXTargets.cmake")