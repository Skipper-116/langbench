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

$start = microtime(true);

$memo = [];
fibonacci(1000, $memo);
$matrixA = generateMatrix(100, 100);
$matrixB = generateMatrix(100, 100);
matrixMultiply($matrixA, $matrixB);

$end = microtime(true);
$elapsed = $end - $start;
echo "Elapsed time PHP: {$elapsed} seconds\n";