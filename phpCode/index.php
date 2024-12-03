<?php

function fibonacci($n, &$memo) {
    if ($n <= 1) return $n;
    if (isset($memo[$n])) return $memo[$n];

    $result = fibonacci($n - 1, $memo) + fibonacci($n - 2, $memo);
    $memo[$n] = $result;
    return $result;
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

function matrixMultiply($matrixA, $matrixB) {
    $rowsA = count($matrixA);
    $colsA = count($matrixA[0]);
    $colsB = count($matrixB[0]);

    $result = [];
    for ($i = 0; $i < $rowsA; $i++) {
        $result[$i] = [];
        for ($j = 0; $j < $colsB; $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < $colsA; $k++) {
                $result[$i][$j] += $matrixA[$i][$k] * $matrixB[$k][$j];
            }
        }
    }
    return $result;
}

$start = microtime(true);

$memo = [];
fibonacci(1000, $memo);
$matrixA = generateMatrix(100, 100);
$matrixB = generateMatrix(100, 100);
matrixMultiply($matrixA, $matrixB);

$end = microtime(true);
$elapsed = $end - $start;
echo "Elapsed time PHP: {$elapsed} seconds\n";