import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        long startTime = System.nanoTime();

        Map<Integer, Long> memo = new HashMap<>();
        fibonacci(1000, memo);

        int[][] matrixA = generateMatrix(100, 100);
        int[][] matrixB = generateMatrix(100, 100);
        matrixMultiply(matrixA, matrixB);

        long endTime = System.nanoTime();
        double elapsedTime = (endTime - startTime) / 1e9;
        System.out.println("Elapsed time Java: " + elapsedTime + " seconds");
    }

    public static long fibonacci(int n, Map<Integer, Long> memo) {
        if (n <= 1) return n;
        if (memo.containsKey(n)) return memo.get(n);

        long result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
        memo.put(n, result);
        return result;
    }

    public static int[][] generateMatrix(int rows, int cols) {
        Random rand = new Random();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand.nextInt(100);
            }
        }
        return matrix;
    }

    public static int[][] matrixMultiply(int[][] a, int[][] b) {
        int rowsA = a.length;
        int colsA = a[0].length;
        int colsB = b[0].length;
        int[][] result = new int[rowsA][colsB];

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }
}
