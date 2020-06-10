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

ColorRGB ColorRGB::operator=(Color *original) {
    r=original->GetChannel(RED);
    g=original->GetChannel(GREEN);
    b=original->GetChannel(BLUE);
    return *this;
}

ColorRGB ColorRGB::operator+(Color *other) {
    r+=other->GetChannel(RED);
    g+=other->GetChannel(GREEN);
    b+=other->GetChannel(BLUE);
    return *this;
}

ColorRGB ColorRGB::operator*(Color *other) {
    r*=other->GetChannel(RED);
    g*=other->GetChannel(GREEN);
    b*=other->GetChannel(BLUE);
    return *this;
}

float ColorRGB::GetChannel(Channel channel) {
    switch(channel){
        case RED : return r;
        case GREEN : return g;
        case BLUE : return b;
        case ALPHA : return 1;
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
    }
}
