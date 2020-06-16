//
// Created by salvi on 6/11/2020.
//

#include "gtest/gtest.h"
#include "../Image.h"
#include "../Color/ColorRGBA.h"


TEST(image_test, image_set) {
    Image<ColorRGBA> image(100,200);
    image.SetPixel(ColorRGBA(1,2,3,4),50,50);
    EXPECT_EQ(2,(image.GetPixel(50,50)).GetChannel(GREEN));
    EXPECT_EQ(100,image.GetWidth());
}
