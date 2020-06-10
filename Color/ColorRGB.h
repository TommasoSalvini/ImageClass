//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLORRGB_H
#define IMAGECLASS_COLORRGB_H


#include "Color.h"

class ColorRGB : public Color {
public:
    ColorRGB();
    ColorRGB(float r,float g,float b);

    ColorRGB operator=(Color* original);
    ColorRGB operator+(Color* other);
    ColorRGB operator*(Color* other);

    float GetChannel(Channel channel) override;
    float GetGrayscaleValue() override;

    void SetChannel(float value, Channel channel) override;


protected:
    float r;
    float g;
    float b;
};


#endif //IMAGECLASS_COLORRGB_H
