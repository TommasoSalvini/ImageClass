//
// Created by salvi on 6/9/2020.
//

#include "ColorGrayscale.h"

ColorGrayscale::ColorGrayscale() {
    value=0;
}

ColorGrayscale::ColorGrayscale(float in_value) {
    value=in_value;
}

ColorGrayscale ColorGrayscale::operator=(Color* original) {
    value =  original->GetGrayscaleValue();
    return *this;
}

ColorGrayscale ColorGrayscale::operator+(Color* other){
    value+=other->GetGrayscaleValue();
    return *this;
}

ColorGrayscale ColorGrayscale::operator*(Color* other) {
    value*=other->GetGrayscaleValue();
    return *this;
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
    ColorGrayscale::value=value;
}

void ColorGrayscale::SetColor(float in_value) {
    value=in_value;
}

void ColorGrayscale::SetColor(float r, float g, float b, float a) {
    value=(r+g+b)/3;
}