//
// Created by salvi on 6/10/2020.
//

#ifndef IMAGECLASS_IMAGELOADER_H
#define IMAGECLASS_IMAGELOADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Image.h"
#include "Color/ColorGrayscale.h"
#include "Color/ColorRGB.h"


template <typename ColorType> class ImageLoader {
public:
    ImageLoader();
    void Write(Image<ColorType> image, std::string path="");
    Image<ColorType> Load(std::string path="");
    int Clamp(int value,int min,int max);

protected:
};


template <typename ColorType> ImageLoader<ColorType>::ImageLoader(){

}

template <typename ColorType> int ImageLoader<ColorType>::Clamp(int value,int min,int max){
    if(value>max){
        return max;
    }else if(value < min){
        return min;
    } else {return value;}
}


template <typename ColorType> void ImageLoader<ColorType>::Write(Image<ColorType> image,std::string path="") {
    auto extension_pos = path.find_last_of(".");
    auto extension=path.substr(extension_pos+1);
    std::ofstream file;
    file.open(path);
    std::string id;
    if(extension=="pgm"){
        id="P2";
    } else if(extension=="ppm"){
        id="P3";
    } else {throw "Invalid extension";}
    file << id << " " << image.GetWidth() << " " << image.GetHeight() << " 255" << std::endl;
    for(int i=0;i<image.GetHeight()*image.GetHeight();i++){
        if(extension=="pgm") {
            file << Clamp((int)((image.GetPixel(i).GetGrayscaleValue())*255),0,255) << " ";
        } else {
            file << Clamp((int)((image.GetPixel(i).GetChannel(RED))*255),0,255) << " " << Clamp((int)((image.GetPixel(i).GetChannel(GREEN))*255),0,255) << " " << Clamp((int)((image.GetPixel(i).GetChannel(BLUE))*255),0,255) << " ";
        }
        if(i>0 && i%image.GetWidth()==0){
            file << std::endl;
        }

    }
    file.close();
}


template <typename ColorType> Image<ColorType> ImageLoader<ColorType>::Load(std::string path=""){
    std::fstream file;
    file.open(path);
    std::string id;
    int width,height,depth;
    std::string current_buffer;
    file>>id;
    file>>width>>height>>depth;
    Image<ColorType> image(width,height);
    for(int i=0;i<width*height;i++){
        if(id=="P2"){
            float grayscale;
            file>>grayscale;
            //float grayscale=std::stof(current_buffer);
            grayscale/=depth;
            image.GetPixel(i).SetColor(grayscale);
        }
        else if(id=="P3"){
            float red,green,blue;
            file>>red>>green>>blue;
            red/=depth;
            green/=depth;
            blue/=depth;
            image.GetPixel(i).SetColor(red,green,blue,1);
        } else {
            throw "Invalid file format";
        }
    }

    file.close();
    return image;
}

#endif //IMAGECLASS_IMAGELOADER_H
