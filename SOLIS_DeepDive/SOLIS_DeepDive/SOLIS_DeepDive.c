/*
Name: SOLIS, Frances Danielle B.
Section: S11
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

void process(int n, int* h_Y, int* h_X) {
    for (int i = 0; i < n-6; i++)
        h_Y[i] = h_X[i] + h_X[i+1] + h_X[i+2] + h_X[i+3] + h_X[i+4] + h_X[i+5] + h_X[i+6];
}

extern void process_ASM(int n, int* d_Y, int* d_X);

//extern void process_SIMD_ASM(int n, int* d_Y, int* d_X);

unsigned int error(int X_SIZE, int* Y, int* Y_ref) {
    unsigned int err_count = 0;
    for (int i = 0; i < X_SIZE-6; i++)
        if (Y_ref[i] != Y[i])
            ++err_count;

    return err_count;
}

    int main() {
        // input data
        long unsigned int X_SIZE;
        printf("Input Vector Size n: 2^");
        scanf_s("%u", &X_SIZE);

        X_SIZE = (long unsigned int)pow(2, X_SIZE);

        const long unsigned int ARRAY_BYTES = X_SIZE * sizeof(int);
        const long unsigned int ARRAY_BYTES_Y = (X_SIZE-6) * sizeof(int);

        printf("Array size: %d\n\n", X_SIZE);

        /* C program */

        // declare ARRAY_BYTES
        int* X, *Y;
        X = (int*)malloc(ARRAY_BYTES);
        Y = (int*)malloc(ARRAY_BYTES_Y);

        // timer variables
        clock_t start, end;

        // init data
        for (int i = 0; i < X_SIZE; i++)
            X[i] = (i + 1) % 1024;

        // flush-in cache
        process(X_SIZE, Y, X);

        // time here
        double total = 0;
        for (int i = 0; i < 30; i++) {
            start = clock();
            process(X_SIZE, Y, X);
            end = clock();
            total += ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC; // microseconds
        }
        double ave_time_C = total / 30.0;
        printf("C function: %lfus\n", ave_time_C);
        printf("Y Vector: %d\t%d\t%d\t%d\t%d\n", Y[0], Y[1], Y[2], Y[3], Y[4]);

        // check for errors

        //make reference Y
        int* Y_temp;
        Y_temp = (int*)malloc(ARRAY_BYTES);
        for (int i = 0; i < X_SIZE-6; i++)
            Y_temp[i] = X[i] + X[i+1] + X[i+2] + X[i+3] + X[i+4] + X[i+5] + X[i+6];

        unsigned int err_count_c = error(X_SIZE, Y, Y_temp);
        printf("Error count: %d \n", err_count_c);
        printf("\n\n");



        /* x86-64 Assembly Language */
        int* Y_ASM;
        Y_ASM = (int*)malloc(ARRAY_BYTES_Y);

        // flush-in cache
        process_ASM(X_SIZE, Y_ASM, X);

        // time here
        total = 0;
        for (int i = 0; i < 30; i++) {
            start = clock();
            process_ASM(X_SIZE, Y_ASM, X);
            end = clock();
            total += ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC; // microseconds
        }
        double ave_time_ASM = total / 30.0;
        printf("ASM function: %lfus\n", ave_time_ASM);
        printf("Y Vector: %d\t%d\t%d\t%d\t%d\n", Y[0], Y[1], Y[2], Y[3], Y[4]);

        // check for errors
        unsigned int err_count_asm = error(X_SIZE, Y_ASM, Y);
        printf("Error count: %d \n", err_count_asm);
        printf("\n\n");

        // free memory
        free(Y_ASM);



        /* x86 SIMD using YMM register 
        int* Y_SIMD;
        Y_SIMD = (int*)malloc(ARRAY_BYTES);

        // flush-in cache
        process_SIMD_ASM(X_SIZE, Y_SIMD, X);

        // time here
        double total = 0;
        for (int i = 0; i < 30; i++) {
            start = clock();
            process_SIMD_ASM(X_SIZE, Y_SIMD, X);
            end = clock();
            total += ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC; // microseconds
        }
        double ave_time_SIMD = total / 30.0;
        printf("SIMD ASM function: %lfus\n", ave_time_SIMD);
        printf("Y Vector: %d\t%d\t%d\t%d\t%d\n", Y[0], Y[1], Y[2], Y[3], Y[4]);

        // check for errors
        unsigned int err_count_SIMD = error(X_SIZE, Y_SIMD, Y);
        printf("Error count: %ld \n", err_count_SIMD);
        printf("\n\n");

        // free memory
        free(X);
        free(Y);
        free(Y_ASM);*/

        return 0;
    }