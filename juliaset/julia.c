
#include "julia.h"
#include <math.h> // For pow() and sqrt() (though not strictly necessary for escape_radius_sq)

// Function to calculate the number of iterations for a point
int calculate_julia_iterations(complex_t z, complex_t c, int max_iterations, double escape_radius_sq) {
    int iteration = 0;
    while (iteration < max_iterations) {
        // Calculate z_new = z*z + c
        // (a + bi)(a + bi) = a*a + 2abi + b*b*i*i = (a*a - b*b) + 2abi
        double z_real_sq = z.real * z.real;
        double z_imag_sq = z.imag * z.imag;

        // Check if the point has escaped (magnitude squared > escape_radius_sq)
        if ((z_real_sq + z_imag_sq) > escape_radius_sq) {
            break;
        }

        double new_real = z_real_sq - z_imag_sq + c.real;
        double new_imag = 2 * z.real * z.imag + c.imag;

        z.real = new_real;
        z.imag = new_imag;

        iteration++;
    }
    return iteration;
}

