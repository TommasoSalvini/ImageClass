//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLORGRAYSCALEALPHA_H
#define IMAGECLASS_COLORGRAYSCALEALPHA_H


#include "ColorGrayscale.h"

class ColorGrayscaleAlpha : public ColorGrayscale {
public:
    ColorGrayscaleAlpha();
    ColorGrayscaleAlpha(float value,float alpha);

    ColorGrayscaleAlpha operator+(Color& other);
    ColorGrayscaleAlpha operator*(float value);

    float GetChannel(Channel channel);

    void SetChannel(float value,Channel channel);
    void SetColor(float r,float g,float b,float a);
    void SetColor(float value,float alpha);

protected:
    float alpha;

};


#endif //IMAGECLASS_COLORGRAYSCALEALPHA_H
