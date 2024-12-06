using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        var stopwatch = Stopwatch.StartNew();
        var memo = new Dictionary<int, long>();
        
        // Fibonacci
        Fibonacci(1000, memo);

        // Matrix multiplication
        int[,] matrixA = GenerateMatrix(100, 100);
        int[,] matrixB = GenerateMatrix(100, 100);
        MatrixMultiply(matrixA, matrixB);

        // Generate dataset
        int[] dataset = GenerateDataset(10000, 1000);

        // Sort using different algorithms
        int[] quicksortDataset = (int[])dataset.Clone();
        int[] mergesortDataset = (int[])dataset.Clone();
        int[] heapsortDataset = (int[])dataset.Clone();
        int[] insertionSortDataset = (int[])dataset.Clone();

        // Sort Algorithms
        Quicksort(quicksortDataset, 0, quicksortDataset.Length - 1);
        Mergesort(mergesortDataset, 0, mergesortDataset.Length - 1);
        Heapsort(heapsortDataset);
        InsertionSort(insertionSortDataset);

        // Search Algorithms
        int target = dataset[new Random().Next(0, dataset.Length)];
        int[] sortedDataset = (int[])dataset.Clone();
        Array.Sort(sortedDataset);
        LinearSearch(dataset, target);
        BinarySearch(sortedDataset, target);

        stopwatch.Stop();
        Console.WriteLine($"Elapsed time C#: {stopwatch.Elapsed.TotalSeconds} seconds");
    }

    static int LinearSearch(int[] array, int target)
    {
        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] == target)
            {
                return i;
            }
        }
        return -1; // Not found
    }

    static int BinarySearch(int[] array, int target)
    {
        int left = 0;
        int right = array.Length - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (array[mid] == target)
            {
                return mid;
            }
            if (array[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1; // Not found
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

    static int[] GenerateDataset(int size, int maxValue)
    {
        var random = new Random();
        int[] dataset = new int[size];
        for (int i = 0; i < size; i++)
        {
            dataset[i] = random.Next(1, maxValue + 1);
        }
        return dataset;
    }

    static void Quicksort(int[] array, int low, int high)
    {
        if (low < high)
        {
            int pi = Partition(array, low, high);
            Quicksort(array, low, pi - 1);
            Quicksort(array, pi + 1, high);
        }
    }

    static int Partition(int[] array, int low, int high)
    {
        int pivot = array[high];
        int i = (low - 1);
        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                Swap(array, i, j);
            }
        }
        Swap(array, i + 1, high);
        return i + 1;
    }

    static void Swap(int[] array, int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    static void Mergesort(int[] array, int left, int right)
    {
        if (left < right)
        {
            int middle = (left + right) / 2;
            Mergesort(array, left, middle);
            Mergesort(array, middle + 1, right);
            Merge(array, left, middle, right);
        }
    }

    static void Merge(int[] array, int left, int middle, int right)
    {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];

        Array.Copy(array, left, leftArray, 0, n1);
        Array.Copy(array, middle + 1, rightArray, 0, n2);

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2)
        {
            if (leftArray[i] <= rightArray[j])
            {
                array[k] = leftArray[i];
                i++;
            }
            else
            {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }

    static void Heapsort(int[] array)
    {
        int n = array.Length;

        for (int i = n / 2 - 1; i >= 0; i--)
            Heapify(array, n, i);

        for (int i = n - 1; i >= 0; i--)
        {
            Swap(array, 0, i);
            Heapify(array, i, 0);
        }
    }

    static void Heapify(int[] array, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && array[left] > array[largest])
            largest = left;

        if (right < n && array[right] > array[largest])
            largest = right;

        if (largest != i)
        {
            Swap(array, i, largest);
            Heapify(array, n, largest);
        }
    }

    static void InsertionSort(int[] array)
    {
        int n = array.Length;
        for (int i = 1; i < n; ++i)
        {
            int key = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
}