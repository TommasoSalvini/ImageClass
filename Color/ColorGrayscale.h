//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLORGRAYSCALE_H
#define IMAGECLASS_COLORGRAYSCALE_H


#include "Color.h"

class ColorGrayscale : public Color {
public:
    ColorGrayscale();
    ColorGrayscale(float in_value);

    ColorGrayscale operator=(Color* original);

    ColorGrayscale operator+(Color* other);

    ColorGrayscale operator*(Color* other);

    float GetChannel(Channel channel);
    float GetGrayscaleValue();

    void SetChannel(float value,Channel channel);
    void SetColor(float r,float g,float b,float a);
    void SetColor(float in_value);


protected:
    float value;
};


#endif //IMAGECLASS_COLORGRAYSCALE_H
