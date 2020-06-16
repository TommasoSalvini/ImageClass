#include <iostream>
#include "Color/ColorGrayscale.h"
#include "Color/ColorGrayscaleAlpha.h"
#include "Color/ColorRGB.h"
#include "Color/ColorRGBA.h"
#include "Image.h"
#include "ImageLoader.h"
#include "KernelProcessor.h"

Image<ColorRGBA> GenerateUVTest(int width,int height){
    Image<ColorRGBA> image(width,height);

    for(float x=0;x<image.GetWidth();x++){
        for(float y=0;y<image.GetHeight();y++){
            float r = x/image.GetWidth();
            float g = y/image.GetHeight();
            ColorRGBA color(r,g,0,1);
            image.SetPixel(color,x,y);
        }
    }
    return image;
}

int main() {


    Image<ColorRGBA> image = Load<ColorRGBA>("snail.ppm");
    Image<ColorRGBA> uvtest = GenerateUVTest(200,200);

    KernelProcessor<ColorRGBA> processor;
    Image<ColorRGBA> final;

    Write<ColorRGBA>(uvtest,"results/uvtest.ppm");

    Write<ColorRGBA>(image,"results/original.ppm");
    processor.SetKernel(processor.blur);
    final = processor.Process(image);
    Write<ColorRGBA>(final,"results/blur.ppm");
    processor.SetKernel(processor.sharpen);
    final = processor.Process(image);
    Write<ColorRGBA>(final,"results/sharpen.ppm");
    processor.SetKernel(processor.emboss);
    final = processor.Process(image);
    Write<ColorRGBA>(final,"results/emboss.ppm");
    processor.SetKernel(processor.outline);
    final = processor.Process(image);
    Write<ColorRGBA>(final,"results/outline.ppm");
    processor.SetKernel(processor.edge);
    final = processor.Process(image);
    Write<ColorRGBA>(final,"results/edge.ppm");

    return 0;
}
