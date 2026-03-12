

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dgemm (size_t n, double* A, double* B, double* C) {
    for (size_t i = 0; i < n; ++i)
        for (size_t k = 0; k < n; ++k) {
            double aik = A[i*n+k]; 
            for(size_t j = 0; j < n; ++j) {
                // This is where the magic happens:
                C[i*n+j] += aik * B[k*n+j];
            }
        }
}

int main() {
    const int n = 1024;
    double *a = (double *)malloc(n * n * sizeof(double));
    double *b = (double *)malloc(n * n * sizeof(double));
    double *c = (double *)malloc(n * n * sizeof(double));

    for(int i=0; i<n*n; i++) { a[i]=1.0; b[i]=2.0; c[i]=0.0; }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    dgemm(n, a, b, c);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Layout: %s | Matrix: %d | Time: %.4f s\n", "Row-major", n, time);

    free(a); free(b); free(c);
    return 0;
}
