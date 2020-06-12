//
// Created by salvi on 6/11/2020.
//

#include "gtest/gtest.h"
#include "../Color/ColorRGBA.h"
#include "../Color/ColorGrayscaleAlpha.h"

TEST(test_color, test_addition) {
    ColorGrayscaleAlpha color1(0.4,0.1);
    ColorGrayscaleAlpha color2(0.6,0.6);
    ColorRGBA color3(0.5,0.7,0.2,1);
    ColorRGBA color4(0.2,0.3,0.8,0.5);
    EXPECT_EQ(1.0,(color1+color2).GetGrayscaleValue());
    EXPECT_EQ(1.0,(color3+color4).GetChannel(GREEN));

}

TEST(test_color, test_multiplication) {
    ColorGrayscaleAlpha color1(0.3,0.2);
    ColorRGBA color2(0.6,1.0,0.3,0.6);
    EXPECT_FLOAT_EQ(0.15,(color1*0.5).GetGrayscaleValue());
    EXPECT_FLOAT_EQ(1.2,(color2*2).GetChannel(RED));

}

TEST(test_color, test_copy_constructor){
    ColorGrayscaleAlpha color1(0.8,1.0);
    ColorRGBA color2(0.3,0.5,0.7,0.9);
    ColorGrayscaleAlpha color3(color1);
    ColorRGBA color4(color2);
    EXPECT_FLOAT_EQ(0.8,color3.GetGrayscaleValue());
    EXPECT_FLOAT_EQ(0.5,color4.GetChannel(GREEN));
}

