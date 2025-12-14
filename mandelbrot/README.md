The mandelbrot() function iterates the classic formula zn+1=zn2+cz_{n+1} = z_n^2 + c until divergence or
MAX_ITER

This uses OpenMP.

#pragma omp parallel for schedule(dynamic) distributes rows across threads for faster rendering.

Uses ANSI 256-color codes (\033[38;5;...m) for richer visualization if the terminal supports it.

Example usage:

## Basic Mandelbrot set
./mandelbrot

## Zoomed-in view at scale 0.5
./mandelbrot 0.5

## Centered at (-0.75, 0.1), animated zoom
./mandelbrot 2.0 -0.75 0.1 yes
