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

ColorRGBA::ColorRGBA(ColorRGBA &other)  : ColorRGB(other) {
    a=other.GetChannel(ALPHA);
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

ColorRGBA ColorRGBA::operator+(Color &other) {
    ColorRGB result = ColorRGB::operator+(other);
    return ColorRGBA(result.GetChannel(RED),result.GetChannel(GREEN),result.GetChannel(BLUE),GetChannel(ALPHA)+other.GetChannel(ALPHA));
}

ColorRGBA ColorRGBA::operator*(float value) {
    return ColorRGBA(GetChannel(RED)*value,GetChannel(GREEN)*value,GetChannel(BLUE)*value,GetChannel(ALPHA)*value);
}
