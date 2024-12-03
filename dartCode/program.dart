import 'dart:collection';
import 'dart:core';

void main() {
  var stopwatch = Stopwatch()..start();
  var memo = HashMap<int, int>();

  fibonacci(1000, memo);
  var matrixA = generateMatrix(100, 100);
  var matrixB = generateMatrix(100, 100);
  matrixMultiply(matrixA, matrixB);

  stopwatch.stop();
  print(
      'Elapsed time Dart: ${stopwatch.elapsed.inMilliseconds / 1000.0} seconds');
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
