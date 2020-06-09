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
