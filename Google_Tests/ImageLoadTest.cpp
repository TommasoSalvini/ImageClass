//
// Created by salvi on 6/11/2020.
//

#include "gtest/gtest.h"
#include "../Image.h"
#include "../ImageLoader.h"
#include "../Color/ColorRGBA.h"

TEST(imageloader_test, test_save_and_load) {
    Image<ColorRGBA> image(10,10);
    image.SetPixel(1,1,1,1,3,3);
    image.SetPixel(0.2,0.3,0.4,0,6,7);
    ImageLoader<ColorRGBA> loader;
    loader.Write(image,"./test.ppm");
    loader.Write(image,"./test.pgm");
    Image<ColorRGBA> imageppm = loader.Load("./test.ppm");
    Image<ColorRGBA> imagepgm = loader.Load("./test.pgm");
    EXPECT_EQ(1,imageppm.GetPixel(3,3).GetChannel(RED));
    EXPECT_NEAR(0.3,imagepgm.GetPixel(6,7).GetGrayscaleValue(),0.02);
}
