#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long Fibonacci(int n, long *memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];

    memo[n] = Fibonacci(n - 1, memo) + Fibonacci(n - 2, memo);
    return memo[n];
}

int** GenerateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Random values for the matrix
        }
    }
    return matrix;
}

void MatrixMultiply(int **matrixA, int **matrixB, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Free the result matrix
    for (int i = 0; i < rows; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int n = 1000;
    long *memo = (long *)malloc((n + 1) * sizeof(long));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    Fibonacci(n, memo);
    free(memo);

    int rows = 100, cols = 100;
    int **matrixA = GenerateMatrix(rows, cols);
    int **matrixB = GenerateMatrix(rows, cols);
    MatrixMultiply(matrixA, matrixB, rows, cols);

    // Free the matrices
    for (int i = 0; i < rows; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
    }
    free(matrixA);
    free(matrixB);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time C: %f seconds\n", cpu_time_used);

    return 0;
}