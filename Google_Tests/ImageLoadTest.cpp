//
// Created by salvi on 6/11/2020.
//

#include "gtest/gtest.h"
#include "../Image.h"
#include "../ImageLoader.h"
#include "../Color/ColorRGBA.h"

TEST(imageloader_test, test_save_and_load) {
    Image<ColorRGBA> image(10,10);
    image.SetPixel(ColorRGBA(1,1,1,1),3,3);
    image.SetPixel(ColorRGBA(0.2,0.3,0.4,0),6,7);
    Write<ColorRGBA>(image,"./test.ppm");
    Write<ColorRGBA>(image,"./test.pgm");
    Image<ColorRGBA> imageppm = Load<ColorRGBA>("./test.ppm");
    Image<ColorRGBA> imagepgm = Load<ColorRGBA>("./test.pgm");
    EXPECT_EQ(1,imageppm.GetPixel(3,3).GetChannel(RED));
    EXPECT_NEAR(0.3,imagepgm.GetPixel(6,7).GetGrayscaleValue(),0.02);
}
