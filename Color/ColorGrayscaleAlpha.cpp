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


float ColorGrayscaleAlpha::GetChannel(Channel channel) {
    if(channel!=ALPHA){
        return value;
    } else {
        return alpha;
    }
}

void ColorGrayscaleAlpha::SetChannel(float value, Channel channel) {
    if(channel==GRAYSCALE){
        ColorGrayscaleAlpha::value=value;
    } else if(channel==ALPHA){
        alpha=value;
    }
}

void ColorGrayscaleAlpha::SetColor(float r, float g, float b, float a) {
    ColorGrayscale::SetColor(r,g,b,1);
    alpha=a;
}

void ColorGrayscaleAlpha::SetColor(float value, float alpha) {
    ColorGrayscaleAlpha::value=value;
    ColorGrayscaleAlpha::alpha=alpha;
}

ColorGrayscaleAlpha ColorGrayscaleAlpha::operator+(Color &other) {
    return ColorGrayscaleAlpha(GetGrayscaleValue()+other.GetGrayscaleValue(),GetChannel(ALPHA)+other.GetChannel(ALPHA));
}

ColorGrayscaleAlpha ColorGrayscaleAlpha::operator*(float value) {
    return ColorGrayscaleAlpha(GetGrayscaleValue()*value,GetChannel(ALPHA)*value);
}
