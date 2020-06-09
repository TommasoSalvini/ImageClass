//
// Created by salvi on 6/9/2020.
//

#include "ColorGrayscaleAlpha.h"

ColorGrayscaleAlpha::ColorGrayscaleAlpha() {
    alpha=0;
}

ColorGrayscaleAlpha::ColorGrayscaleAlpha(float value, float alpha) {
    ColorGrayscaleAlpha::value=value;
    ColorGrayscaleAlpha::alpha=alpha;
}

ColorGrayscaleAlpha ColorGrayscaleAlpha::operator=(Color* other){
    value=other->GetGrayscaleValue();
    alpha=other->GetChannel(ALPHA);
    return *this;
}

ColorGrayscaleAlpha ColorGrayscaleAlpha::operator+(Color* other){
    value+=other->GetGrayscaleValue();
    alpha+=other->GetChannel(ALPHA);
    return *this;
}

ColorGrayscaleAlpha ColorGrayscaleAlpha::operator*(Color* other){
    value*=other->GetGrayscaleValue();
    alpha*=other->GetChannel(ALPHA);
    return *this;
}

float ColorGrayscaleAlpha::GetChannel(Channel channel) {
    if(channel!=ALPHA){
        return value;
    } else {
        return alpha;
    }
}

void ColorGrayscaleAlpha::SetChannel(float value, Channel channel) {
    if(channel!=ALPHA){
        ColorGrayscaleAlpha::value=value;
    } else {
        alpha=value;
    }
}

void ColorGrayscaleAlpha::SetColor(float r, float g, float b, float a) {
    ColorGrayscale::SetColor(r,g,b,1);
    alpha=alpha;
}

void ColorGrayscaleAlpha::SetColor(float value, float alpha) {
    ColorGrayscaleAlpha::value=value;
    ColorGrayscaleAlpha::alpha=alpha;
}