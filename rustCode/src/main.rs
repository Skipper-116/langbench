use std::collections::HashMap;
use std::time::Instant;
use rand::Rng;

fn main() {
    let start = Instant::now();
    let mut memo = HashMap::new();

    // Compute Fibonacci
    fibonacci(1000, &mut memo);

    // Generate matrices and multiply
    let matrix_a = generate_matrix(100, 100);
    let matrix_b = generate_matrix(100, 100);
    let _result = matrix_multiply(&matrix_a, &matrix_b);

    let elapsed = start.elapsed();
    println!("Elapsed time Rust: {:.2} seconds", elapsed.as_secs_f64());
}

fn fibonacci(n: usize, memo: &mut HashMap<usize, u64>) -> u64 {
    if n <= 1 {
        return n as u64;
    }
    if let Some(&result) = memo.get(&n) {
        return result;
    }
    let result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    memo.insert(n, result);
    result
}

fn generate_matrix(rows: usize, cols: usize) -> Vec<Vec<i32>> {
    let mut rng = rand::thread_rng();
    (0..rows)
        .map(|_| (0..cols).map(|_| rng.gen_range(0..100)).collect())
        .collect()
}

fn matrix_multiply(a: &[Vec<i32>], b: &[Vec<i32>]) -> Vec<Vec<i32>> {
    let rows_a = a.len();
    let cols_a = a[0].len();
    let cols_b = b[0].len();
    let mut result = vec![vec![0; cols_b]; rows_a];

    for i in 0..rows_a {
        for j in 0..cols_b {
            for k in 0..cols_a {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    result
}
