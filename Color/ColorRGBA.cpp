//
// Created by salvi on 6/9/2020.
//

#include "ColorRGBA.h"

ColorRGBA::ColorRGBA() {
    SetChannel(0,ALL);
}

ColorRGBA::ColorRGBA(float r, float g, float b, float a) {
    ColorRGBA::r=r;
    ColorRGBA::g=g;
    ColorRGBA::b=b;
    ColorRGBA::a=a;
}

ColorRGBA ColorRGBA::operator=(Color* original) {
    ColorRGB::operator=(original);
    a=original->GetChannel(ALPHA);
    return *this;
}

ColorRGBA ColorRGBA::operator+(Color* other) {
    ColorRGB::operator+(other);
    a+=other->GetChannel(ALPHA);
    return *this;
}

ColorRGBA ColorRGBA::operator*(Color* other) {
    ColorRGB::operator*(other);
    a*=other->GetChannel(ALPHA);
    return *this;
}

float ColorRGBA::GetChannel(Channel channel) {
    if(channel!=ALPHA){
        return ColorRGB::GetChannel(channel);
    } else {return a;}
}


void ColorRGBA::SetChannel(float value, Channel channel) {
    if(channel!=ALPHA){
        ColorRGB::SetChannel(value, channel);
    } else {
        a=value;
    }
}
