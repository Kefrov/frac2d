#include <complex>
#include <cmath>
#include "fractal.hpp"

const int MAX_ITER = 1000;

static SDL_Color calcColor(int iter) {
    Uint8 r = static_cast<Uint8>((3 * iter) % 230);
    Uint8 g = static_cast<Uint8>((3 * iter) % 230);
    Uint8 b = static_cast<Uint8>((3 * iter) % 230);
    return {r, g, b, 255};
}

SDL_Color getColor(double x, double y) {
    std::complex<double> z(0, 0);
    std::complex<double> c(x, y);

    for (int i = 0; i < MAX_ITER; i++) {
        z = z * z + c;
        if (std::abs(z) > 2.0) {
            return calcColor(i);
        }
    }
    return {0, 0, 0, 255};
}
