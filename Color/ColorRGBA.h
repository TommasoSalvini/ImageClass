//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLORRGBA_H
#define IMAGECLASS_COLORRGBA_H


#include "ColorRGB.h"

class ColorRGBA : public ColorRGB{
public:
    ColorRGBA();
    ColorRGBA(float r,float g,float b,float a);
    ColorRGBA(ColorRGBA& other);

    ColorRGBA operator+(Color& other);
    ColorRGBA operator*(float value);

    float GetChannel(Channel channel);

    void SetChannel(float value, Channel channel);

protected:
    float a;
};


#endif //IMAGECLASS_COLORRGBA_H
