cmake_minimum_required(VERSION 3.16)
project(ImageClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(ImageClass main.cpp Image.cpp Image.h Color.cpp Color.h ColorGrayscale.cpp ColorGrayscale.h ColorGrayscaleAlpha.cpp ColorGrayscaleAlpha.h ColorRGB.cpp ColorRGB.h ColorRGBA.cpp ColorRGBA.h)