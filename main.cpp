#include <iostream>
#include "ColorGrayscale.h"
#include "ColorGrayscaleAlpha.h"

int main() {
    ColorGrayscale color(0.5);
    ColorGrayscaleAlpha color2(0.2,0.5);

    std::cout << color.GetChannel(RED) << std::endl;

    color2 = color2+&color;

    std::cout << color2.GetGrayscaleValue() << " " << color2.GetChannel(ALPHA) << std::endl;
    return 0;
}
