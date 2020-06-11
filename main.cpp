#include <iostream>
#include "Color/ColorGrayscale.h"
#include "Color/ColorGrayscaleAlpha.h"
#include "Color/ColorRGB.h"
#include "Color/ColorRGBA.h"
#include "Image.h"
#include "ImageLoader.h"
#include "KernelProcessor.h"

Image<ColorRGB> GenerateUVTest(int width,int height){
    Image<ColorRGB> image(width,height);

    for(float x=0;x<image.GetWidth();x++){
        for(float y=0;y<image.GetHeight();y++){
            float r = x/image.GetWidth();
            float g = y/image.GetHeight();
            ColorRGB color(r,g,0);
            image.SetPixel(color,x,y);
        }
    }
    return image;
}

int main() {


    ImageLoader<ColorRGBA> loader;
    Image<ColorRGBA> image = loader.Load("snail.ppm");
    std::cout << image.GetHeight() << " " << image.GetWidth() << std::endl;

    KernelProcessor<ColorRGBA> processor(&image);
    Image<ColorRGBA> final;

    final = processor.Process(processor.blur);
    loader.Write(final,"results/2.ppm");
    final = processor.Process(processor.sharpen);
    loader.Write(final,"results/3.ppm");
    final = processor.Process(processor.emboss);
    loader.Write(final,"results/4.ppm");
    final = processor.Process(processor.outline);
    loader.Write(final,"results/5.ppm");
    final = processor.Process(processor.edge);
    loader.Write(final,"results/6.ppm");

    loader.Write(image,"results/1.ppm");
    return 0;
}
