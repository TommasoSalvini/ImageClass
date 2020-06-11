//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_COLOR_H
#define IMAGECLASS_COLOR_H

//#include <vector>

enum Channel {RED,GREEN,BLUE,ALPHA,GRAYSCALE,ALL};

class Color {
public:
 //TODO copy constructor

/*    virtual Color& operator=(const Color &other);
    virtual Color operator+(const Color &other);
    virtual Color operator*(float value);*/

    virtual float GetChannel(Channel channel)=0;
    virtual float GetGrayscaleValue()=0;

    virtual void SetChannel(float value,Channel channel)=0;
    virtual void SetColor(float r,float g,float b,float a);
    virtual void SetColor(float in_value);



protected:
    //std::vector<Channel> channels;
};


#endif //IMAGECLASS_COLOR_H
