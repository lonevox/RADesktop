cmake_minimum_required(VERSION 4.2)
project(RADesktop_NativeCore VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# Path to the submodule
set(RCHEEVOS_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../third_party/rcheevos")

# Collect rcheevos sources (directory-based)
file(GLOB_RECURSE RCHEEVOS_SOURCES CONFIGURE_DEPENDS
  "${RCHEEVOS_ROOT}/src/*.c"
  "${RCHEEVOS_ROOT}/src/rcheevos/*.c"
  "${RCHEEVOS_ROOT}/src/rapi/*.c"
  "${RCHEEVOS_ROOT}/src/rhash/*.c"
)

# Exclude sources rcheevos itself excludes (see Package.swift)
list(FILTER RCHEEVOS_SOURCES EXCLUDE REGEX "rc_libretro\\.c$")
list(FILTER RCHEEVOS_SOURCES EXCLUDE REGEX "rc_client_external\\.c$")

add_library(rcheevos STATIC ${RCHEEVOS_SOURCES})

target_include_directories(rcheevos PUBLIC
  "${RCHEEVOS_ROOT}/include"
)

# Match rcheevos build defines used by the Swift package
target_compile_definitions(rcheevos PUBLIC
  RC_DISABLE_LUA
  RC_CLIENT_SUPPORTS_HASH
)

# RADesktop native core
add_library(RADesktop.NativeCore SHARED
  src/radesktop_native.cpp
)

target_compile_features(RADesktop.NativeCore PRIVATE cxx_std_20)
target_include_directories(RADesktop.NativeCore PUBLIC
  include
)

target_link_libraries(RADesktop.NativeCore PRIVATE rcheevos)
target_compile_definitions(RADesktop.NativeCore PRIVATE RADESKTOP_NATIVECORE_EXPORTS)
