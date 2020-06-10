#include <iostream>
#include "Color/ColorGrayscale.h"
#include "Color/ColorGrayscaleAlpha.h"
#include "Color/ColorRGB.h"
#include "Color/ColorRGBA.h"
#include "Image.h"
#include "ImageLoader.h"
#include "KernelProcessor.h"

int main() {

    Image<ColorRGB> image1(100,100);
    //std::cout << image1.GetWidth() << " " << image1.GetHeight() << std::endl;

    for(float x=0;x<image1.GetWidth();x++){
        for(float y=0;y<image1.GetHeight();y++){
            float r = x/image1.GetWidth();
            float g = y/image1.GetHeight();
            //std::cout << x << " " << y << std::endl;
            ColorRGB color(r,g,0);
            //std::cout << color.GetChannel(RED) << " " << color.GetChannel(GREEN) << " " << color.GetChannel(BLUE) << std::endl;
            image1.SetPixel(color,x,y);
        }
    }
    ColorRGB color(0.5,0.2,0.1);
    image1.SetPixel(color,13,15);

    ImageLoader<ColorRGB> loader;
    Image<ColorRGB> image = loader.Load("snail.ascii.ppm");
    std::cout << image.GetHeight() << " " << image.GetWidth() << std::endl;

    KernelProcessor<ColorRGB> processor(&image);
    float kernel[] = {0,-1,0,-1,-5,-1,0,-1,0};
    Image<ColorRGB> final = processor.Process(kernel);

    loader.Write(final,"result.ppm");


    return 0;
}
