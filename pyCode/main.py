import time
import sys

def fibonacci(n, memo):
    if n <= 1:
        return n
    if n in memo:
        return memo[n]

    result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    memo[n] = result
    return result

def generate_matrix(rows, cols):
    return [[1 for _ in range(cols)] for _ in range(rows)]

def matrix_multiply(matrixA, matrixB):
    rowsA = len(matrixA)
    colsA = len(matrixA[0])
    colsB = len(matrixB[0])
    
    result = [[0 for _ in range(colsB)] for _ in range(rowsA)]
    
    for i in range(rowsA):
        for j in range(colsB):
            for k in range(colsA):
                result[i][j] += matrixA[i][k] * matrixB[k][j]
    
    return result

if __name__ == "__main__":
    sys.setrecursionlimit(2000)  # Increase the recursion limit
    start_time = time.time()
    memo = {}
    
    fibonacci(1000, memo)
    matrixA = generate_matrix(100, 100)
    matrixB = generate_matrix(100, 100)
    matrix_multiply(matrixA, matrixB)
    
    elapsed_time = time.time() - start_time
    print(f"Elapsed time Python: {elapsed_time} seconds")