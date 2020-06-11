//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLOR_H
#define IMAGECLASS_COLOR_H

//#include <vector>

enum Channel {RED,GREEN,BLUE,ALPHA,GRAYSCALE,ALL};

class Color {
public:
    virtual float GetChannel(Channel channel)=0;
    virtual float GetGrayscaleValue()=0;

    virtual void SetChannel(float value,Channel channel)=0;
    virtual void SetColor(float r,float g,float b,float a);
    virtual void SetColor(float in_value);


};


#endif //IMAGECLASS_COLOR_H
