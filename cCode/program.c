#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Linear Search
int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Binary Search
int binary_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// Jump Search
// int jump_search(int arr[], int n, int x) {
//     int step = sqrt(n);
//     int prev = 0;
//     while (arr[min(step, n) - 1] < x) {
//         prev = step;
//         step += sqrt(n);
//         if (prev >= n)
//             return -1;
//     }
//     for (int i = prev; i < min(step, n); i++) {
//         if (arr[i] == x)
//             return i;
//     }
//     return -1;
// }

// // Exponential Search
// int exponential_search(int arr[], int n, int x) {
//     if (arr[0] == x)
//         return 0;
//     int i = 1;
//     while (i < n && arr[i] <= x)
//         i = i * 2;
//     return binary_search(arr, i / 2, min(i, n - 1), x);
// }

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

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

    // Sorting algorithms
    int dataset_size = 10000;
    int *dataset = (int *)malloc(dataset_size * sizeof(int));
    for (int i = 0; i < dataset_size; i++) {
        dataset[i] = rand() % 1000 + 1;
    }

    // Quicksort
    int *qs_dataset = (int *)malloc(dataset_size * sizeof(int));
    memcpy(qs_dataset, dataset, dataset_size * sizeof(int));
    quicksort(qs_dataset, 0, dataset_size - 1);
    

    // merge_sort
    int *ms_dataset = (int *)malloc(dataset_size * sizeof(int));
    memcpy(ms_dataset, dataset, dataset_size * sizeof(int));
    merge_sort(ms_dataset, 0, dataset_size - 1);
    

    // heap_sort
    int *hs_dataset = (int *)malloc(dataset_size * sizeof(int));
    memcpy(hs_dataset, dataset, dataset_size * sizeof(int));
    heap_sort(hs_dataset, dataset_size);
    

    // Insertion sort
    int *is_dataset = (int *)malloc(dataset_size * sizeof(int));
    memcpy(is_dataset, dataset, dataset_size * sizeof(int));
    insertionsort(is_dataset, dataset_size);

    free(qs_dataset);
    free(ms_dataset);
    free(hs_dataset);
    free(is_dataset);
    free(dataset);


    // searching algorithms
    int search_dataset_size = 10000;
    int *search_dataset = (int *)malloc(search_dataset_size * sizeof(int));

    for (int i = 0; i < search_dataset_size; i++) {
        search_dataset[i] = rand() % 1000 + 1;
    }

    int x = search_dataset[0];
    linear_search(search_dataset, search_dataset_size, x);
    binary_search(search_dataset, 0, search_dataset_size - 1, x);
    // jump_search(search_dataset, search_dataset_size, x);
    // exponential_search(search_dataset, search_dataset_size, x);

    free(search_dataset);


    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time C: %f seconds\n", cpu_time_used);

    return 0;
}