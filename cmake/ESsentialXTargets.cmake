# Minimal ESsentialXTargets.cmake
# Creates an IMPORTED target ESsentialX::esx that points to a built library inside the ESsentialX source tree.
# Probes common output locations including 'cmake-build-debug' (CLion default).

if(NOT TARGET ESsentialX::esx)

    # root dir = parent of the 'cmake' dir where this file lives
    get_filename_component(_esx_root "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

    # candidate library file locations (include CLion build dir 'cmake-build-debug')
    set(_candidate_libs
            "${_esx_root}/cmake-build-debug/ESsentialX.lib"
            "${_esx_root}/cmake-build-debug/Debug/ESsentialX.lib"
            "${_esx_root}/cmake-build-debug/Release/ESsentialX.lib"
            "${_esx_root}/build/ESsentialX.lib"
            "${_esx_root}/build/Debug/ESsentialX.lib"
            "${_esx_root}/build/Release/ESsentialX.lib"
            "${_esx_root}/lib/ESsentialX.lib"
            "${_esx_root}/lib/libESsentialX.a"
            "${_esx_root}/build/libESsentialX.a"
            "${_esx_root}/build/ESsentialX.a"
            "${_esx_root}/lib/ESsentialX.dll"
            "${_esx_root}/build/ESsentialX.dll"
            "${_esx_root}/build/Debug/ESsentialX.dll"
            "${_esx_root}/lib/ESsentialX.so"
            "${_esx_root}/lib/libESsentialX.so"
    )

    set(_found_lib "")
    foreach(_cand IN LISTS _candidate_libs)
        if(EXISTS "${_cand}")
            set(_found_lib "${_cand}")
            break()
        endif()
    endforeach()

    if(NOT _found_lib)
        message(FATAL_ERROR "
ESsentialX: could not find a built library for ESsentialX in the source tree.
Please build ESsentialX first (in: ${_esx_root}) so that a library file exists.
Searched these locations:
${_candidate_libs}

Common quick build commands (from ESsentialX source dir):
  mkdir build
  cmake -S . -B build
  cmake --build build --config Debug

If you used CLion, check the 'cmake-build-debug' folder — this script already looks there.
")
    endif()

    add_library(ESsentialX::esx UNKNOWN IMPORTED)
    set_target_properties(ESsentialX::esx PROPERTIES
            IMPORTED_LOCATION "${_found_lib}"
            INTERFACE_INCLUDE_DIRECTORIES "${_esx_root}/include"
    )

endif()