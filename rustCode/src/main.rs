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

    // Generate dataset
    let dataset: Vec<i32> = (0..10_000).map(|_| rand::thread_rng().gen_range(1..1_000)).collect();

    // Sort using different algorithms
    let mut dataset_quick = dataset.clone();
    quicksort(&mut dataset_quick);

    let mut dataset_merge = dataset.clone();
    mergesort(&mut dataset_merge);

    let mut dataset_heap = dataset.clone();
    heapsort(&mut dataset_heap);

    let mut dataset_insertion = dataset.clone();
    insertion_sort(&mut dataset_insertion);

    let elapsed = start.elapsed();
    println!("Elapsed time Rust: {:.8} seconds", elapsed.as_secs_f64());
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

fn quicksort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }
    let pivot_index = partition(arr);
    quicksort(&mut arr[0..pivot_index]);
    quicksort(&mut arr[pivot_index + 1..]);
}

fn partition(arr: &mut [i32]) -> usize {
    let pivot_index = arr.len() / 2;
    arr.swap(pivot_index, arr.len() - 1);
    let mut i = 0;
    for j in 0..arr.len() - 1 {
        if arr[j] < arr[arr.len() - 1] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, arr.len() - 1);
    i
}

fn mergesort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }
    let mid = arr.len() / 2;
    mergesort(&mut arr[0..mid]);
    mergesort(&mut arr[mid..]);
    let mut temp = arr.to_vec();
    merge(&arr[0..mid], &arr[mid..], &mut temp);
    arr.copy_from_slice(&temp);
}

fn merge(left: &[i32], right: &[i32], result: &mut [i32]) {
    let mut left_index = 0;
    let mut right_index = 0;
    let mut result_index = 0;
    while left_index < left.len() && right_index < right.len() {
        if left[left_index] <= right[right_index] {
            result[result_index] = left[left_index];
            left_index += 1;
        } else {
            result[result_index] = right[right_index];
            right_index += 1;
        }
        result_index += 1;
    }
    if left_index < left.len() {
        result[result_index..].copy_from_slice(&left[left_index..]);
    }
    if right_index < right.len() {
        result[result_index..].copy_from_slice(&right[right_index..]);
    }
}

fn heapsort(arr: &mut [i32]) {
    let len = arr.len();
    for i in (0..len / 2).rev() {
        heapify(arr, len, i);
    }
    for i in (1..len).rev() {
        arr.swap(0, i);
        heapify(arr, i, 0);
    }
}

fn heapify(arr: &mut [i32], len: usize, i: usize) {
    let mut largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;
    if left < len && arr[left] > arr[largest] {
        largest = left;
    }
    if right < len && arr[right] > arr[largest] {
        largest = right;
    }
    if largest != i {
        arr.swap(i, largest);
        heapify(arr, len, largest);
    }
}

fn insertion_sort(arr: &mut [i32]) {
    for i in 1..arr.len() {
        let key = arr[i];
        let mut j = i;
        while j > 0 && arr[j - 1] > key {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = key;
    }
}