#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void saxpy_asm(float A, float* X, float* Y, float* Z, int n);

void saxpy_c(float A, float* X, float* Y, float* Z, int n) {
    for (int i = 0; i < n; ++i) {
        Z[i] = A * X[i] + Y[i];
    }
}

int main() {
    int sizes[] = { pow(2, 20), pow(2, 24), pow(2, 27) };
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    float A = 2.0f;

    for (int k = 0; k < num_sizes; ++k) {
        int n = sizes[k];

        float* X = (float*)malloc(n * sizeof(float));
        float* Y = (float*)malloc(n * sizeof(float));
        float* Z_c = (float*)malloc(n * sizeof(float));
        float* Z_asm = (float*)malloc(n * sizeof(float));

        // Initialize X and Y vectors with random values between 0 and 100
        for (int i = 0; i < n; ++i) {
            X[i] = ((float)rand() / (float)RAND_MAX) * 100;
            Y[i] = ((float)rand() / (float)RAND_MAX) * 100;
        }

        clock_t start, end;
        double cpu_time_used;

        // Time C version
        start = clock();
        for (int i = 0; i < 30; ++i) {
            saxpy_c(A, X, Y, Z_c, n);
        }
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC / 30.0;

        printf("C version time for n = %d: %f seconds\n", n, cpu_time_used);

        // Output first 10 elements of Z_c
        printf("C version output for n = %d (first 10 elements):\n", n);
        for (int i = 0; i < 10; ++i) {
            printf("%f ", Z_c[i]);
        }
        printf("\n\n");

        // Time assembly version
        start = clock();
        for (int i = 0; i < 30; ++i) {
            saxpy_asm(A, X, Y, Z_asm, n);
        }
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC / 30.0;

        printf("Assembly version time for n = %d: %f seconds\n", n, cpu_time_used);

        // Output first 10 elements of Z_asm
        printf("Assembly version output for n = %d (first 10 elements):\n", n);
        for (int i = 0; i < 10; ++i) {
            printf("%f ", Z_asm[i]);
        }
        printf("\n\n");

        free(X);
        free(Y);
        free(Z_c);
        free(Z_asm);
    }

    return 0;
}

