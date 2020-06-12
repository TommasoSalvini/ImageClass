//
// Created by salvi on 6/12/2020.
//

#include "gtest/gtest.h"
#include "../Image.h"
#include "../Color/ColorGrayscale.h"
#include "../KernelProcessor.h"

TEST(kernel_test, test_calculation) {
    Image<ColorGrayscale> image(3,3);
    ColorGrayscale color(1);
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            image.SetPixel(color,x,y);
        }
    }
    float kernel[9] = {0.0,1.0,0.0,1.0,0.0,1.0,0.0,1.0,0.0};
    KernelProcessor<ColorGrayscale> processor(&image);
    EXPECT_FLOAT_EQ(4,processor.CalculateKernelColor(1,1,kernel).GetGrayscaleValue());
}
