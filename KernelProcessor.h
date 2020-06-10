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

protected:
    Image<ColorType>* image;
};


template<typename ColorType> KernelProcessor<ColorType>::KernelProcessor(){
    image = new Image<ColorType>;
}
template<typename ColorType> void KernelProcessor<ColorType>::SetImage(Image<ColorType> *image){
    KernelProcessor<ColorType>::image=image;
}
template<typename ColorType> KernelProcessor<ColorType>::KernelProcessor(Image<ColorType>* image){
    SetImage(image);
}
template<typename ColorType> Image<ColorType> KernelProcessor<ColorType>::Process(float kernel[9]){
    Image<ColorType> final_image(image->GetWidth(),image->GetHeight());
    ColorType final;
    ColorType current_color;
    ColorType* center;
    for(int x=0;x<image->GetWidth();x++){
        for(int y=0;y<image->GetHeight();y++){
            final.SetColor(0);
            center = &(image->GetPixel(x,y));
            int kernel_index=0;
            //final.SetColor(0);
            for(int j=-1;j<=1;j++){
                for(int i=-1;i<=1;i++){
                    if(x+i<0 || x+i>=image->GetWidth() || y+j<0 || y+j>=image->GetWidth()){
                        current_color=*center;
                        //SetColor(1);
                    } else { current_color=(image->GetPixel(x+i,y+j));}
                    //std::cout << current_color.GetChannel(RED) << current_color.GetChannel(GREEN) << current_color.GetChannel(BLUE);
                    ColorGrayscale kernel_color(kernel[kernel_index]);
                    //std::cout << kernel_color.GetGrayscaleValue();
                    final=&(final+&(current_color*&kernel_color));
                    kernel_index++;
                    //std::cout<<final.GetChannel(RED)<<final.GetChannel(GREEN)<<final.GetChannel(BLUE)<<std::endl;

                }
            }
            final_image.GetPixel(x,y) = &final;
            //std::cout<<std::endl;
        }
    }
    return final_image;
}


#endif //IMAGECLASS_KERNELPROCESSOR_H
