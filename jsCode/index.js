const startTime = Date.now();

function fibonacci(n, memo = {}) {
    if (n <= 1) return n;
    if (memo[n]) return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

function generateMatrix(rows, cols) {
    let matrix = [];
    for (let i = 0; i < rows; i++) {
        matrix[i] = [];
        for (let j = 0; j < cols; j++) {
            matrix[i][j] = Math.floor(Math.random() * 100);
        }
    }
    return matrix;
}

function matrixMultiply(matrixA, matrixB) {
    let result = [];
    let rowsA = matrixA.length, colsA = matrixA[0].length;
    let rowsB = matrixB.length, colsB = matrixB[0].length;

    if (colsA !== rowsB) throw new Error("Matrices cannot be multiplied");

    for (let i = 0; i < rowsA; i++) {
        result[i] = [];
        for (let j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (let k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

// Generate a random dataset
function generateRandomDataset(size, max) {
    return Array.from({ length: size }, () => Math.floor(Math.random() * max) + 1);
}

// Quicksort
function quicksort(arr) {
    if (arr.length <= 1) return arr;
    let pivot = arr[Math.floor(arr.length / 2)];
    let left = arr.filter(x => x < pivot);
    let middle = arr.filter(x => x === pivot);
    let right = arr.filter(x => x > pivot);
    return [...quicksort(left), ...middle, ...quicksort(right)];
}

// Mergesort
function mergesort(arr) {
    if (arr.length <= 1) return arr;
    const middle = Math.floor(arr.length / 2);
    const left = arr.slice(0, middle);
    const right = arr.slice(middle);
    return merge(mergesort(left), mergesort(right));
}

function merge(left, right) {
    let result = [], leftIndex = 0, rightIndex = 0;
    while (leftIndex < left.length && rightIndex < right.length) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push(left[leftIndex]);
            leftIndex++;
        } else {
            result.push(right[rightIndex]);
            rightIndex++;
        }
    }
    return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
}

// Heapsort
function heapsort(arr) {
    let heapSize = arr.length;
    buildMaxHeap(arr);
    for (let i = arr.length - 1; i > 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        heapSize--;
        heapify(arr, 0, heapSize);
    }
    return arr;
}

function buildMaxHeap(arr) {
    for (let i = Math.floor(arr.length / 2); i >= 0; i--) {
        heapify(arr, i, arr.length);
    }
}

function heapify(arr, i, heapSize) {
    let largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;
    if (left < heapSize && arr[left] > arr[largest]) largest = left;
    if (right < heapSize && arr[right] > arr[largest]) largest = right;
    if (largest !== i) {
        [arr[i], arr[largest]] = [arr[largest], arr[i]];
        heapify(arr, largest, heapSize);
    }
}

// Insertion sort
function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let key = arr[i];
        let j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

fibonacci(1000);

let matrixA = generateMatrix(100, 100);
let matrixB = generateMatrix(100, 100);
matrixMultiply(matrixA, matrixB);

// Generate dataset
let dataset = generateRandomDataset(10000, 1000);
quicksort([...dataset]);
mergesort([...dataset]);
heapsort([...dataset]);
insertionSort([...dataset]);

const endTime = Date.now();
const elapsedTime = (endTime - startTime) / 1000;
console.log(`Elapsed time JS: ${elapsedTime} seconds`);