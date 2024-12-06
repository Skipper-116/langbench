import 'dart:collection';
import 'dart:core';
import 'dart:ffi';
import 'dart:math';

void main() {
  var stopwatch = Stopwatch()..start();
  var memo = HashMap<int, int>();

  //Fibonacci
  fibonacci(1000, memo);

  // matrix multiplication
  var matrixA = generateMatrix(100, 100);
  var matrixB = generateMatrix(100, 100);
  matrixMultiply(matrixA, matrixB);

  var dataset = generateDataset(10000, 1000);

  // Sorting algorithms
  var quicksortDataset = List<int>.from(dataset);
  quicksort(quicksortDataset, 0, quicksortDataset.length - 1);

  var mergesortDataset = List<int>.from(dataset);
  mergesort(mergesortDataset, 0, mergesortDataset.length - 1);

  var heapsortDataset = List<int>.from(dataset);
  heapsort(heapsortDataset);

  var insertionSortDataset = List<int>.from(dataset);
  insertionSort(insertionSortDataset);

  // Searching algorithms
  // target should be random number from range 1 to 100000
  var target = Random().nextInt(100000) + 1;
  linearSearch(dataset, target);
  var sortedDataset = List<int>.from(dataset)..sort();
  binarySearch(sortedDataset, target);

  stopwatch.stop();
  var time = stopwatch.elapsed.inMilliseconds / 1000.0;
  print('Elapsed time Dart: ${time} seconds');
}

int linearSearch(List<int> array, int target) {
  for (int i = 0; i < array.length; i++) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1; // Not found
}

int binarySearch(List<int> array, int target) {
  int left = 0;
  int right = array.length - 1;

  while (left <= right) {
    int middle = left + (right - left) ~/ 2;

    if (array[middle] == target) {
      return middle;
    } else if (array[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1; // Not found
}

int fibonacci(int n, HashMap<int, int> memo) {
  if (n <= 1) return n;
  if (memo.containsKey(n)) return memo[n]!;

  int result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
  memo[n] = result;
  return result;
}

List<List<int>> generateMatrix(int rows, int cols) {
  var matrix = List.generate(rows, (_) => List.generate(cols, (_) => 1));
  return matrix;
}

List<List<int>> matrixMultiply(
    List<List<int>> matrixA, List<List<int>> matrixB) {
  int rowsA = matrixA.length;
  int colsA = matrixA[0].length;
  int colsB = matrixB[0].length;

  var result = List.generate(rowsA, (_) => List.generate(colsB, (_) => 0));

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      for (int k = 0; k < colsA; k++) {
        result[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  return result;
}

List<int> generateDataset(int size, int max) {
  var random = Random();
  return List.generate(size, (_) => random.nextInt(max) + 1);
}

void quicksort(List<int> list, int left, int right) {
  if (left < right) {
    int pivotIndex = partition(list, left, right);
    quicksort(list, left, pivotIndex - 1);
    quicksort(list, pivotIndex + 1, right);
  }
}

int partition(List<int> list, int left, int right) {
  int pivot = list[right];
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (list[j] <= pivot) {
      i++;
      swap(list, i, j);
    }
  }
  swap(list, i + 1, right);
  return i + 1;
}

void swap(List<int> list, int i, int j) {
  int temp = list[i];
  list[i] = list[j];
  list[j] = temp;
}

void mergesort(List<int> list, int left, int right) {
  if (left < right) {
    int middle = (left + right) ~/ 2;
    mergesort(list, left, middle);
    mergesort(list, middle + 1, right);
    merge(list, left, middle, right);
  }
}

void merge(List<int> list, int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;

  List<int> leftList = List<int>.filled(n1, 0);
  List<int> rightList = List<int>.filled(n2, 0);

  for (int i = 0; i < n1; i++) leftList[i] = list[left + i];
  for (int j = 0; j < n2; j++) rightList[j] = list[middle + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (leftList[i] <= rightList[j]) {
      list[k] = leftList[i];
      i++;
    } else {
      list[k] = rightList[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    list[k] = leftList[i];
    i++;
    k++;
  }

  while (j < n2) {
    list[k] = rightList[j];
    j++;
    k++;
  }
}

void heapsort(List<int> list) {
  int n = list.length;

  for (int i = n ~/ 2 - 1; i >= 0; i--) {
    heapify(list, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(list, 0, i);
    heapify(list, i, 0);
  }
}

void heapify(List<int> list, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && list[left] > list[largest]) largest = left;
  if (right < n && list[right] > list[largest]) largest = right;

  if (largest != i) {
    swap(list, i, largest);
    heapify(list, n, largest);
  }
}

void insertionSort(List<int> list) {
  for (int i = 1; i < list.length; i++) {
    int key = list[i];
    int j = i - 1;
    while (j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j--;
    }
    list[j + 1] = key;
  }
}
