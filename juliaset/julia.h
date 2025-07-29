
#ifndef JULIA_H
#define JULIA_H

// Structure to represent a complex number (z = real + i * imag)
typedef struct {
    double real;
    double imag;
} complex_t;

// Function to calculate the number of iterations for a point
// before it escapes a certain radius or reaches max_iterations.
// Returns the iteration count.
int calculate_julia_iterations(complex_t z, complex_t c, int max_iterations, double escape_radius_sq);

#endif // JULIA_H

