//
// Created by salvi on 6/10/2020.
//

#ifndef IMAGECLASS_KERNELPROCESSOR_H
#define IMAGECLASS_KERNELPROCESSOR_H

#include "Image.h"

template <typename ColorType> class KernelProcessor {
public:
    KernelProcessor();
    KernelProcessor(Image<ColorType>* image);

    void SetImage(Image<ColorType>* image);
    Image<ColorType> Process(float kernel[9]);
    ColorType CalculateKernelColor(int x,int y,float kernel[9]);
    float identity[9] = {0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0};
    float blur[9] = {0.0625,0.125,0.0625,0.125,0.25,0.125,0.0625,0.125,0.0625};
    float outline[9] = {-1.0,-1.0,-1.0,-1.0,8.0,-1.0,-1.0,-1.0,-1.0};
    float sharpen[9] = {0.0,-1.0,0.0,-1.0,5.0,-1.0,0.0,-1.0,0.0};
    float emboss[9] = {-2.0,-1.0,0.0,-1.0,1.0,1.0,0.0,1.0,2.0};
    float edge[9]  = {0.0,0.0,0.0,-1.0,1.0,0.0,0.0,0.0};

protected:
    Image<ColorType>* image;
};


template<typename ColorType> KernelProcessor<ColorType>::KernelProcessor(){
    image = new Image<ColorType>;
}
template<typename ColorType> void KernelProcessor<ColorType>::SetImage(Image<ColorType>* image){
    KernelProcessor<ColorType>::image=image;
}
template<typename ColorType> KernelProcessor<ColorType>::KernelProcessor(Image<ColorType>* image){
    SetImage(image);
}

template<typename ColorType> ColorType KernelProcessor<ColorType>::CalculateKernelColor(int x,int y,float kernel[9]){
    ColorType final;
    ColorType current_color;
    final.SetColor(0.0);
    int kernel_index=0;
    for(int j=-1;j<=1;j++){
        for(int i=-1;i<=1;i++){
            if(x+i<0 || x+i>=image->GetWidth() || y+j<0 || y+j>=image->GetHeight()){
                current_color=(image->GetPixel(x,y));
            } else { current_color=(image->GetPixel(x+i,y+j));}
            final=final+(current_color*kernel[kernel_index]);
            kernel_index++;

        }
    }
    return final;

}

template<typename ColorType> Image<ColorType> KernelProcessor<ColorType>::Process(float kernel[9]){
    int width=image->GetWidth();
    int height=image->GetHeight();
    Image<ColorType> final_image(width,height);
    for(int y=0;y<width;y++){
        for(int x=0;x<height;x++){
            ColorType final = CalculateKernelColor(x,y,kernel);
            final_image.SetPixel(final,x,y);
        }
    }
    return final_image;
}

#endif //IMAGECLASS_KERNELPROCESSOR_H
