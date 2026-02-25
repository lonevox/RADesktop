cmake_minimum_required(VERSION 4.2)
project(RADesktop_NativeCore VERSION 0.1.0 LANGUAGES C CXX)

add_library(RADesktop.NativeCore SHARED
  src/radesktop_native.cpp
)

target_compile_features(RADesktop.NativeCore PRIVATE cxx_std_20)
target_include_directories(RADesktop.NativeCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Export a stable C ABI (important for P/Invoke)
target_compile_definitions(RADesktop.NativeCore PRIVATE RADESKTOP_NATIVECORE_EXPORTS)
