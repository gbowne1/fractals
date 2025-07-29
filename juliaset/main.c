
#include <stdio.h>
#include <stdlib.h>

// Include our custom Julia set header
#include "julia.h"

int main() {
    // A classic Julia set example
    // --- Julia Set Parameters ---
    // The constant 'c' for the Julia set equation: z_new = z*z + c
    // Experiment with different c values to see different fractals!
    complex_t c = {-0.7, 0.27015};

    // --- Image / Grid Parameters ---
    const int width = 80;   // Characters wide for console output
    const int height = 40;  // Characters high for console output
    const int max_iterations = 100; // Max iterations before we assume convergence
    const double escape_radius = 2.0; // If magnitude of z > 2, it escapes
    const double escape_radius_sq = escape_radius * escape_radius;

    // --- Mapping Coordinates ---
    // The complex plane region to render: [x_min, x_max] x [y_min, y_max]
    const double x_min = -1.5;
    const double x_max = 1.5;
    const double y_min = -1.0;
    const double y_max = 1.0;

    printf("Generating Julia Set for c = (%.4f, %.4f)\n", c.real, c.imag);
    printf("--- Output (Console Characters) ---\n");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Map pixel coordinates (x, y) to complex plane coordinates (z.real, z.imag)
            complex_t z;
            z.real = x_min + (double)x / (width - 1) * (x_max - x_min);
            z.imag = y_max - (double)y / (height - 1) * (y_max - y_min); // Y-axis inverted for display

            int iterations = calculate_julia_iterations(z, c, max_iterations, escape_radius_sq);

            // Simple character mapping for console output
            if (iterations == max_iterations) {
                printf("#"); // Point is likely inside the set
            } else {
                // Map iteration count to different characters for a basic "coloring" effect
                // Using direct iteration count for character assignment
                if (iterations < max_iterations / 10) { // e.g., < 10 for max_iterations = 100
                    printf(".");
                } else if (iterations < max_iterations / 5) { // e.g., < 20
                    printf(",");
                } else if (iterations < max_iterations / 2.5) { // e.g., < 40
                    printf("o");
                } else if (iterations < max_iterations / 1.25) { // e.g., < 80
                    printf("O");
                } else {
                    printf(" "); // Point escapes very quickly or very slowly but not converged
                }
            }
        }
        printf("\n"); // New line after each row
    }

    printf("----------------------------------\n");
    return EXIT_SUCCESS;
}

