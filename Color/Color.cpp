//
// Created by salvi on 6/9/2020.
//

#include "Color.h"

void Color::SetColor(float r, float g, float b, float a) {
    SetChannel(r,RED);
    SetChannel(g,GREEN);
    SetChannel(b,BLUE);
    SetChannel(a,ALPHA);
}

void Color::SetColor(float in_value) {
    SetChannel(in_value,ALL);
}



/*Color& Color::operator=(const Color &other) {
    for( auto i = channels.begin();i<channels.end();i++){
        SetChannel(other.GetChannel(*i),*i);
    }
    return this&;
}

Color Color::operator+(const Color &other) {
    Color color;
    for( auto i = channels.begin();i<channels.end();i++){
        color.SetChannel(other.GetChannel(*i)+GetChannel(*i),*i);
    }
    return color;
}
Color Color::operator*(float value) {
    Color color;
    for( auto i = channels.begin();i<channels.end();i++){
        color.SetChannel(GetChannel(*i)*value,*i);
    }
    return color;
}*/