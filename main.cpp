#include <iostream>
#include "ColorGrayscale.h"
#include "ColorGrayscaleAlpha.h"
#include "ColorRGB.h"
#include "ColorRGBA.h"

int main() {
    ColorGrayscale color(0.5);
    ColorGrayscaleAlpha color2(0.2,0.5);
    ColorRGB red(1,0,0);
    ColorRGB light_blue(0.3,0.3,1);
    ColorRGBA transparent_green(0,1,0,1);


    color2 = color2+&color;
    ColorRGB* multiplied_color;
    multiplied_color = &(transparent_green*&light_blue);

    std::cout << multiplied_color->GetGrayscaleValue() << " " << multiplied_color->GetChannel(ALPHA) << std::endl;
    return 0;
}
