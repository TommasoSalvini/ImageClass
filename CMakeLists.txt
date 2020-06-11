cmake_minimum_required(VERSION 3.16)
project(ImageClass)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_Tests)

set(SOURCE_FILES Image.h Color/Color.cpp Color/Color.h Color/ColorGrayscale.cpp Color/ColorGrayscale.h Color/ColorGrayscaleAlpha.cpp Color/ColorGrayscaleAlpha.h Color/ColorRGB.cpp Color/ColorRGB.h Color/ColorRGBA.cpp Color/ColorRGBA.h ImageLoader.h KernelProcessor.h)
add_executable(ImageClass main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ImageClass core)
