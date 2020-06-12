//
// Created by salvi on 6/9/2020.
//

#include "ColorGrayscale.h"

ColorGrayscale::ColorGrayscale() {
    value=0;
}

ColorGrayscale::ColorGrayscale(float value) {
    ColorGrayscale::value=value;
}

ColorGrayscale::ColorGrayscale(ColorGrayscale &other) {
    value=other.GetGrayscaleValue();
}

float ColorGrayscale::GetChannel(Channel channel) {
    if(channel!=ALPHA){
        return value;
    } else {
        return 1;
    }
}

float ColorGrayscale::GetGrayscaleValue() {
    return value;
}

void ColorGrayscale::SetChannel(float value, Channel channel) {
    if(channel==GRAYSCALE){
        ColorGrayscale::value=value;
    }
}

void ColorGrayscale::SetColor(float value) {
    ColorGrayscale::value=value;
}

void ColorGrayscale::SetColor(float r, float g, float b, float a) {
    value=(r+g+b)/3;
}


ColorGrayscale ColorGrayscale::operator+(Color &other) {
    return ColorGrayscale(GetGrayscaleValue()+other.GetGrayscaleValue());
}

ColorGrayscale ColorGrayscale::operator*(float value) {
    return ColorGrayscale(GetGrayscaleValue()*value);
}
