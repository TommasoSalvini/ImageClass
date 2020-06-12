//
// Created by salvi on 6/9/2020.
//

#include "ColorRGB.h"

ColorRGB::ColorRGB() {
    SetChannel(0,ALL);
}

ColorRGB::ColorRGB(float r, float g, float b) {
    ColorRGB::r=r;
    ColorRGB::g=g;
    ColorRGB::b=b;
}

ColorRGB::ColorRGB(ColorRGB &other) {
    r=other.GetChannel(RED);
    g=other.GetChannel(GREEN);
    b=other.GetChannel(BLUE);
}

float ColorRGB::GetChannel(Channel channel) {
    switch(channel){
        case RED : return r;
        case GREEN : return g;
        case BLUE : return b;
        case ALPHA : return 1;
        case GRAYSCALE : return GetGrayscaleValue();
    }
}

float ColorRGB::GetGrayscaleValue() {
    return (r+g+b)/3;
}

void ColorRGB::SetChannel(float value, Channel channel) {
    switch(channel){
        case RED : r=value; break;
        case GREEN : g=value; break;
        case BLUE : b=value; break;
        case ALL : r=value; g=value; b=value; break;
        case GRAYSCALE : r=value; g=value; b=value; break;
    }
}

ColorRGB ColorRGB::operator+(Color &other) {
    return ColorRGB(GetChannel(RED)+other.GetChannel(RED),GetChannel(GREEN)+other.GetChannel(GREEN),GetChannel(BLUE)+other.GetChannel(BLUE));
}

ColorRGB ColorRGB::operator*(float value) {
    return ColorRGB(GetChannel(RED)*value,GetChannel(GREEN)*value,GetChannel(BLUE)*value);
}
