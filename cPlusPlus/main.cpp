#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

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

int main() {
    high_resolution_clock::time_point start = high_resolution_clock::now();
    unordered_map<int, long> memo;

    Fibonacci(1000, memo);
    vector<vector<int> > matrixA = GenerateMatrix(100, 100);
    vector<vector<int> > matrixB = GenerateMatrix(100, 100);
    MatrixMultiply(matrixA, matrixB);

    high_resolution_clock::time_point stop = high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = duration_cast<std::chrono::duration<double, std::milli> >(stop - start);
    double seconds = duration.count() / 1000.0;
    cout << "Elapsed time C++: " << seconds << " seconds" << endl;

    return 0;
}