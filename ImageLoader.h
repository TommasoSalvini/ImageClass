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



template <typename ColorType> void Write(Image<ColorType> image, std::string path="", int depth=255);
template <typename ColorType> Image<ColorType> Load(std::string path="");
int Clamp(int value,int min,int max);




int Clamp(int value,int min,int max){
    if(value>max){
        return max;
    }else if(value < min){
        return min;
    } else {return value;}
}


template <typename ColorType> void Write<ColorType>(Image<ColorType> image,std::string path, int depth) {
    auto extension_pos = path.find_last_of(".");
    auto extension=path.substr(extension_pos+1);
    std::ofstream file;
    file.open(path);
    std::string id;
    if(extension=="pgm"){
        id="P2";
    } else if(extension=="ppm"){
        id="P3";
    }
    file << id << " " << image.GetWidth() << " " << image.GetHeight() << " "<< depth << std::endl;
    for(int y=0;y<image.GetHeight();y++){
        for(int x=0;x<image.GetWidth();x++){
            if(extension=="pgm") {
                file << Clamp((int)((image.GetPixel(x,y).GetGrayscaleValue())*depth),0,depth) << " ";
            } else if(extension=="ppm") {
                file << Clamp((int)((image.GetPixel(x,y).GetChannel(RED))*depth),0,depth) << " " << Clamp((int)((image.GetPixel(x,y).GetChannel(GREEN))*depth),0,depth) << " " << Clamp((int)((image.GetPixel(x,y).GetChannel(BLUE))*depth),0,depth) << " ";
            }
        }
        file << std::endl;
    }
    file.close();
}


template <typename ColorType> Image<ColorType> Load<ColorType>(std::string path){
    std::fstream file;
    file.open(path);
    std::string id;
    int width,height,depth;
    std::string current_buffer;
    file>>id;
    file>>width>>height>>depth;
    Image<ColorType> image(width,height);
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if(id=="P2"){
                float grayscale;
                file>>grayscale;
                grayscale/=depth;
                image.GetPixel(x,y).SetColor(grayscale);
            }
            else if(id=="P3"){
                float red,green,blue;
                file>>red>>green>>blue;
                red/=depth;
                green/=depth;
                blue/=depth;
                image.GetPixel(x,y).SetColor(red,green,blue,1);
            }
        }

    }

    file.close();
    return image;
}

#endif //IMAGECLASS_IMAGELOADER_H
