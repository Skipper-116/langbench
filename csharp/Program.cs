using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        var stopwatch = Stopwatch.StartNew();
        var memo = new Dictionary<int, long>();
        
        Fibonacci(1000, memo);
        int[,] matrixA = GenerateMatrix(100, 100);
        int[,] matrixB = GenerateMatrix(100, 100);
        MatrixMultiply(matrixA, matrixB);

        stopwatch.Stop();
        Console.WriteLine($"Elapsed time C#: {stopwatch.Elapsed.TotalSeconds} seconds");
    }

    static long Fibonacci(int n, Dictionary<int, long> memo)
    {
        if (n <= 1) return n;
        if (memo.ContainsKey(n)) return memo[n];

        long result = Fibonacci(n - 1, memo) + Fibonacci(n - 2, memo);
        memo[n] = result;
        return result;
    }

    static int[,] GenerateMatrix(int rows, int cols)
    {
        var rand = new Random();
        int[,] matrix = new int[rows, cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i, j] = rand.Next(100);
            }
        }
        return matrix;
    }

    static int[,] MatrixMultiply(int[,] a, int[,] b)
    {
        int rowsA = a.GetLength(0);
        int colsA = a.GetLength(1);
        int colsB = b.GetLength(1);
        int[,] result = new int[rowsA, colsB];

        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsB; j++)
            {
                for (int k = 0; k < colsA; k++)
                {
                    result[i, j] += a[i, k] * b[k, j];
                }
            }
        }
        return result;
    }
}