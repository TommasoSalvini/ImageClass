//
// Created by salvi on 6/9/2020.
//

#ifndef IMAGECLASS_IMAGE_H
#define IMAGECLASS_IMAGE_H

#include <vector>
#include <exception>


template <typename ColorType> class Image {
public:
    Image() : Image(100,100) {};
    Image(int width,int height);
    //Image(const Image &original);

    ColorType& GetPixel(int x,int y);
    void SetPixel(ColorType color,int x,int y);
    int GetWidth();
    int GetHeight();

protected:

    int width=0;
    int height=0;
    std::vector<ColorType> pixels;
};

template<typename ColorType> Image<ColorType>::Image(int width,int height){
    Image<ColorType>::width=width;
    Image<ColorType>::height=height;
    pixels.resize(width*height);
}

template<typename ColorType> ColorType& Image<ColorType>::GetPixel(int x,int y){
    if(x<0 || x>=width || y<0 || y>=height){
        throw std::out_of_range("Invalid pixel coordinate");
    } else {
        //std::cout<<(width*y)+x<<std::endl;
        return pixels[(width*y)+x ];
    }
}

template<typename ColorType> void Image<ColorType>::SetPixel(ColorType color,int x,int y){
    try {
        GetPixel(x,y) = color;
    }
    catch(std::out_of_range& exception){
        throw exception;
    }

}

template<typename ColorType> int Image<typename ColorType>::GetWidth() {
    return width;
}

template<typename ColorType> int Image<typename ColorType>::GetHeight() {
    return height;
}

#endif //IMAGECLASS_IMAGE_H
