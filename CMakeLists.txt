cmake_minimum_required(VERSION 3.16)
project(ImageClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(ImageClass main.cpp Image.cpp Image.h Color/Color.cpp Color/Color.h Color/ColorGrayscale.cpp Color/ColorGrayscale.h Color/ColorGrayscaleAlpha.cpp Color/ColorGrayscaleAlpha.h Color/ColorRGB.cpp Color/ColorRGB.h Color/ColorRGBA.cpp Color/ColorRGBA.h ImageLoader.cpp ImageLoader.h KernelProcessor.cpp KernelProcessor.h)