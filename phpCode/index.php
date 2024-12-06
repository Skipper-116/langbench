<?php
function matrixMultiply($matrixA, $matrixB) {
    $rowsA = count($matrixA);
    $colsA = count($matrixA[0]);
    $colsB = count($matrixB[0]);
    $result = array_fill(0, $rowsA, array_fill(0, $colsB, 0));

    for ($i = 0; $i < $rowsA; $i++) {
        for ($j = 0; $j < $colsB; $j++) {
            $sum = 0;
            for ($k = 0; $k < $colsA; $k++) {
                $sum += $matrixA[$i][$k] * $matrixB[$k][$j];
            }
            $result[$i][$j] = $sum;
        }
    }
    return $result;
}

function fibonacci($n, &$memo) {
    if ($n <= 1) {
        return $n;
    }
    if (isset($memo[$n])) {
        return $memo[$n];
    }
    $memo[$n] = fibonacci($n - 1, $memo) + fibonacci($n - 2, $memo);
    return $memo[$n];
}

function generateMatrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $matrix[$i] = [];
        for ($j = 0; $j < $cols; $j++) {
            $matrix[$i][$j] = rand(0, 100);
        }
    }
    return $matrix;
}

function quicksort(&$array, $low, $high) {
    if ($low < $high) {
        $pi = partition($array, $low, $high);
        quicksort($array, $low, $pi - 1);
        quicksort($array, $pi + 1, $high);
    }
}

function partition(&$array, $low, $high) {
    $pivot = $array[$high];
    $i = ($low - 1);
    for ($j = $low; $j <= $high - 1; $j++) {
        if ($array[$j] < $pivot) {
            $i++;
            swap($array, $i, $j);
        }
    }
    swap($array, $i + 1, $high);
    return ($i + 1);
}

function swap(&$array, $a, $b) {
    $temp = $array[$a];
    $array[$a] = $array[$b];
    $array[$b] = $temp;
}

function mergesort(&$array) {
    if (count($array) <= 1) {
        return $array;
    }
    $mid = (int)(count($array) / 2);
    $left = array_slice($array, 0, $mid);
    $right = array_slice($array, $mid);
    mergesort($left);
    mergesort($right);
    $array = merge($left, $right);
}

function merge($left, $right) {
    $result = [];
    while (count($left) > 0 && count($right) > 0) {
        if ($left[0] < $right[0]) {
            $result[] = array_shift($left);
        } else {
            $result[] = array_shift($right);
        }
    }
    array_splice($result, count($result), 0, $left);
    array_splice($result, count($result), 0, $right);
    return $result;
}

function heapsort(&$array) {
    $n = count($array);
    for ($i = (int)($n / 2) - 1; $i >= 0; $i--) {
        heapify($array, $n, $i);
    }
    for ($i = $n - 1; $i > 0; $i--) {
        swap($array, 0, $i);
        heapify($array, $i, 0);
    }
}

function heapify(&$array, $n, $i) {
    $largest = $i;
    $left = 2 * $i + 1;
    $right = 2 * $i + 2;
    if ($left < $n && $array[$left] > $array[$largest]) {
        $largest = $left;
    }
    if ($right < $n && $array[$right] > $array[$largest]) {
        $largest = $right;
    }
    if ($largest != $i) {
        swap($array, $i, $largest);
        heapify($array, $n, $largest);
    }
}

function insertionSort(&$array) {
    $n = count($array);
    for ($i = 1; $i < $n; $i++) {
        $key = $array[$i];
        $j = $i - 1;
        while ($j >= 0 && $array[$j] > $key) {
            $array[$j + 1] = $array[$j];
            $j--;
        }
        $array[$j + 1] = $key;
    }
}

function generateRandomArray($size, $maxValue) {
    $array = [];
    for ($i = 0; $i < $size; $i++) {
        $array[] = rand(1, $maxValue);
    }
    return $array;
}

function binarySearch($arr, $x) {
    $l = 0;
    $r = count($arr) - 1;
    while ($l <= $r) {
        $m = floor(($l + $r) / 2);
        if ($arr[$m] == $x) {
            return $m;
        }
        if ($arr[$m] < $x) {
            $l = $m + 1;
        } else {
            $r = $m - 1;
        }
    }
    return -1;
}

function linearSearch($arr, $x) {
    for ($i = 0; $i < count($arr); $i++) {
        if ($arr[$i] == $x) {
            return $i;
        }
    }
    return -1;
}

$start = microtime(true);

$memo = [];
fibonacci(1000, $memo);

$matrixA = generateMatrix(100, 100);
$matrixB = generateMatrix(100, 100);
matrixMultiply($matrixA, $matrixB);

$randomArray = generateRandomArray(10000, 1000);
$quicksortArray = $randomArray;
$mergesortArray = $randomArray;
$heapsortArray = $randomArray;
$insertionSortArray = $randomArray;
quicksort($quicksortArray, 0, count($quicksortArray) - 1);
mergesort($mergesortArray);
heapsort($heapsortArray);
insertionSort($insertionSortArray);


// Generate large sorted and unsorted arrays
$sortedArray = range(1, 100000);
$unsortedArray = $sortedArray;
shuffle($unsortedArray);

// Perform searches searchElement should be random
$searchElement = rand(1, 100000);
binarySearch($sortedArray, $searchElement);
linearSearch($unsortedArray, $searchElement);

$end = microtime(true);
$elapsed = $end - $start;
echo "Elapsed time PHP: {$elapsed} seconds\n";