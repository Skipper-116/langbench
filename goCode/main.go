package main

import (
    "fmt"
    "time"
)

func main() {
    start := time.Now()

    memo := make(map[int]int64)
    Fibonacci(1000, memo)

    matrixA := GenerateMatrix(100, 100)
    matrixB := GenerateMatrix(100, 100)
    MatrixMultiply(matrixA, matrixB)

    elapsed := time.Since(start)
    fmt.Printf("Elapsed time Go: %f seconds\n", elapsed.Seconds())
}

func Fibonacci(n int, memo map[int]int64) int64 {
    if n <= 1 {
        return int64(n)
    }
    if val, ok := memo[n]; ok {
        return val
    }

    result := Fibonacci(n-1, memo) + Fibonacci(n-2, memo)
    memo[n] = result
    return result
}

func GenerateMatrix(rows, cols int) [][]int {
    matrix := make([][]int, rows)
    for i := range matrix {
        matrix[i] = make([]int, cols)
        for j := range matrix[i] {
            matrix[i][j] = i + j // Example initialization
        }
    }
    return matrix
}

func MatrixMultiply(a, b [][]int) [][]int {
    rowsA, colsA := len(a), len(a[0])
    _, colsB := len(b), len(b[0])
    result := make([][]int, rowsA)
    for i := range result {
        result[i] = make([]int, colsB)
        for j := range result[i] {
            for k := 0; k < colsA; k++ {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    return result
}