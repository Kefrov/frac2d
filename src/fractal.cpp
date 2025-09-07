#include <complex>
#include "fractal.hpp"

const int MAX_ITER = 500;

bool inSet(double x, double y) {
    std::complex<double> z(0, 0);
    std::complex<double> c(x, y);
    
    for (int i = 0; i < MAX_ITER; i++) {
        z = z * z + c;
        if (std::abs(z) > 2.0) 
            return false;
    }
    return true;
}

// TODO: Add a static getColor() function
