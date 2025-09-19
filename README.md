Here are the gcc commands to compile/build this in each directory"

`gcc -std=c11 -Wall -Wextra -Werror -Wpedantic -pedantic-errors -o julia main.c julia.c`

`gcc -std=c11 -Wall -Wextra -Werror -fopenmp -o mandelbrot mandelbrot.c -lm`

This requires libgomp1 for GCC so if you use LLVM/Clang it will be using different packages

Please see your package manager and search for OpenMP 
