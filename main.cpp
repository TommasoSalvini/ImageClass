#include <iostream>
#include "Color/ColorGrayscale.h"
#include "Color/ColorGrayscaleAlpha.h"
#include "Color/ColorRGB.h"
#include "Color/ColorRGBA.h"
#include "Image.h"

int main() {

    Image<ColorRGB> image1;
    std::cout << image1.GetWidth() << " " << image1.GetHeight() << std::endl;

    ColorRGB color(0.5,0.2,0.1);
    image1.SetPixel(color,13,15);

    image1.GetPixel(13,15)+&(ColorRGBA(1,0.1,0.2,0));

    std::cout << image1.GetPixel(13,15).GetChannel(RED) << std::endl;
    std::cout << image1.GetPixel(14,15).GetChannel(RED) << std::endl;

    return 0;
}
