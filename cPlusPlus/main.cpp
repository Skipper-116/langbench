#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

long Fibonacci(int n, unordered_map<int, long>& memo) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    memo[n] = Fibonacci(n - 1, memo) + Fibonacci(n - 2, memo);
    return memo[n];
}

vector<vector<int> > GenerateMatrix(int rows, int cols) {
    vector<vector<int> > matrix(rows, vector<int>(cols, 1)); // Example: fill with 1s
    return matrix;
}

vector<vector<int> > MatrixMultiply(const vector<vector<int> >& matrixA, const vector<vector<int> >& matrixB) {
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();
    vector<vector<int> > result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort
void QuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

void Merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Mergesort
void MergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

// Heapsort
void Heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) Heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

// Insertion sort
void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Binary Search implementation
int BinarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

// Linear Search implementation
int LinearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

int main() {
    high_resolution_clock::time_point start = high_resolution_clock::now();
    unordered_map<int, long> memo;

    Fibonacci(1000, memo);
    vector<vector<int> > matrixA = GenerateMatrix(100, 100);
    vector<vector<int> > matrixB = GenerateMatrix(100, 100);
    MatrixMultiply(matrixA, matrixB);

    // Generate dataset
    vector<int> dataset(10000);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for (int& num : dataset) {
        num = dis(gen);
    }

    // Sort using different algorithms
    vector<int> quicksort_dataset = dataset;
    vector<int> mergesort_dataset = dataset;
    vector<int> heapsort_dataset = dataset;
    vector<int> insertionsort_dataset = dataset;

    QuickSort(quicksort_dataset, 0, quicksort_dataset.size() - 1);
    MergeSort(mergesort_dataset, 0, mergesort_dataset.size() - 1);
    HeapSort(heapsort_dataset);
    InsertionSort(insertionsort_dataset);

    // Search for a target and the target should be random
    int target = dataset[dis(gen)];
    vector<int> sorted_array = quicksort_dataset;
    vector<int> unsorted_array = dataset;

    BinarySearch(sorted_array, target);
    LinearSearch(unsorted_array, target);

    high_resolution_clock::time_point stop = high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = duration_cast<std::chrono::duration<double, std::milli> >(stop - start);
    double seconds = duration.count() / 1000.0;
    cout << "Elapsed time C++: " << seconds << " seconds" << endl;

    return 0;
}