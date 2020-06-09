//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLOR_H
#define IMAGECLASS_COLOR_H

enum Channel {RED,GREEN,BLUE,ALPHA};

class Color {
public:

/*    virtual Color operator=(const Color &other)=0;
    virtual Color operator+(const Color &other)=0;
    virtual Color operator*(const Color &other)=0;*/

    virtual float GetChannel(Channel channel)=0;
    virtual float GetGrayscaleValue()=0;

    virtual void SetChannel(float value,Channel channel)=0;
    virtual void SetColor(float r,float g,float b,float a)=0;
    virtual void SetColor(float in_value)=0;
};


#endif //IMAGECLASS_COLOR_H
