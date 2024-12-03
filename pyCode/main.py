import sys
import time
import numpy as np

def generate_matrix(rows, cols):
    return np.random.randint(0, 10, (rows, cols))

def fibonacci(n, memo):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo)
    return memo[n]

def matrix_multiply(matrixA, matrixB):
    return np.dot(matrixA, matrixB)

if __name__ == "__main__":
    sys.setrecursionlimit(2000)  # Increase the recursion limit
    start_time = time.time()
    memo = {}
    
    fibonacci(1000, memo)
    matrixA = generate_matrix(100, 100)
    matrixB = generate_matrix(100, 100)
    result = matrix_multiply(matrixA, matrixB)
    
    elapsed_time = time.time() - start_time
    print(f"Elapsed time Python: {elapsed_time} seconds")