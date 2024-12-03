console.time("Elapsed time JS");

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

fibonacci(1000);
let matrixA = generateMatrix(100, 100);
let matrixB = generateMatrix(100, 100);
matrixMultiply(matrixA, matrixB);

console.timeEnd("Elapsed time JS");