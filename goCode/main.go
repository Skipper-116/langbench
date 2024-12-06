package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func main() {
	start := time.Now()

	// Fibonacci with memoization
	memo := make(map[int]int64)
	Fibonacci(1000, memo)

	// Matrix multiplication
	matrixA := GenerateMatrix(100, 100)
	matrixB := GenerateMatrix(100, 100)
	MatrixMultiply(matrixA, matrixB)

	// Sorting algorithms
	rand.Seed(time.Now().UnixNano())
	datasetOne := GenerateDataset()
	datasetTwo := GenerateDataset()
	datasetThree := GenerateDataset()
	datasetFour := GenerateDataset()

	quicksort(datasetOne)
	mergesort(datasetTwo)
	heapsort(datasetThree)
	insertionSort(datasetFour)

	// Searching algorithms
	// random number to search
	target := rand.Intn(1000) + 1
	sort.Ints(datasetOne)
	BinarySearch(datasetOne, target)
	LinearSearch(datasetTwo, target)

	elapsed := time.Since(start)
	fmt.Printf("Elapsed time Go: %f seconds\n", elapsed.Seconds())
}

func GenerateDataset() []int {
	dataset := make([]int, 10000)
	for i := range dataset {
		dataset[i] = rand.Intn(1000) + 1
	}
	return dataset
}

func BinarySearch(arr []int, target int) int {
	left, right := 0, len(arr)-1
	for left <= right {
		mid := left + (right-left)/2
		if arr[mid] == target {
			return mid
		}
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1 // Target not found
}

func LinearSearch(arr []int, target int) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1 // Target not found
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

func quicksort(arr []int) {
	if len(arr) < 2 {
		return
	}
	left, right := 0, len(arr)-1
	pivot := rand.Int() % len(arr)
	arr[pivot], arr[right] = arr[right], arr[pivot]
	for i := range arr {
		if arr[i] < arr[right] {
			arr[i], arr[left] = arr[left], arr[i]
			left++
		}
	}
	arr[left], arr[right] = arr[right], arr[left]
	quicksort(arr[:left])
	quicksort(arr[left+1:])
}

func mergesort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}
	mid := len(arr) / 2
	return merge(mergesort(arr[:mid]), mergesort(arr[mid:]))
}

func merge(left, right []int) []int {
	result := make([]int, 0, len(left)+len(right))
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}
	result = append(result, left[i:]...)
	result = append(result, right[j:]...)
	return result
}

func heapsort(arr []int) {
	buildMaxHeap(arr)
	for i := len(arr) - 1; i > 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		maxHeapify(arr[:i], 0)
	}
}

func buildMaxHeap(arr []int) {
	for i := len(arr)/2 - 1; i >= 0; i-- {
		maxHeapify(arr, i)
	}
}

func maxHeapify(arr []int, i int) {
	left := 2*i + 1
	right := 2*i + 2
	largest := i
	if left < len(arr) && arr[left] > arr[largest] {
		largest = left
	}
	if right < len(arr) && arr[right] > arr[largest] {
		largest = right
	}
	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i]
		maxHeapify(arr, largest)
	}
}

func insertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}
