#include <iostream>

#include <mkl_types.h>
#include <mkl_cblas.h>
#include <stdio.h>

#include <mkl.h>

#define GENERAL_MATRIX 0
#define UPPER_MATRIX 1
#define LOWER_MATRIX -1

#define FULLPRINT 0
#define SHORTPRINT 1

int main() {
    MKL_INT n, incx, incy;
    float *x, *y;
    float res;
    MKL_INT len_x, len_y;

    n = 5;
    incx = 2;
    incy = 1;

    len_x = 1 + (n-1) * abs(incx);
    len_y = 1 + (n-1) * abs(incy);

    std::cout << "len_x = " << len_x << ", len_y = " << len_y << std::endl;

    x = (float *) calloc(len_x, sizeof(float));
    y = (float *) calloc(len_y, sizeof(float));

    if (x == NULL || y == NULL) {
        std::cerr << "Can't allocate memory" << std::endl;
        return 1;
    }

    for (MKL_INT i = 0; i < n; i++) {
        x[i * abs(incx)] = 2.0;
        y[i * abs(incy)] = 1.0;
    }

    for (MKL_INT i = 0; i < len_x; i++) {
        std::cout << x[i] << ", ";
    }
    std::cout << std::endl;
    for (MKL_INT j = 0; j < len_y; j++) {
        std::cout << y[j] << ", ";
    }
    std::cout << std::endl;

    res = cblas_sdot(n, x, incx, y, incy);

    std::cout << "SDOT = " << res << std::endl;

    free(x);
    free(y);

    return 0;
}