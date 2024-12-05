# frozen_string_literal: true

# frozen_string_literal: true

require 'matrix'

def fibonacci(num)
  return num if num <= 1

  fib = [0, 1]
  (2..num).each do |i|
    fib[i] = fib[i - 1] + fib[i - 2]
  end
  fib[num]
end

def matrix_multiply(a, b)
  a_matrix = Matrix[*a]
  b_matrix = Matrix[*b]
  (a_matrix * b_matrix).to_a
end

def quicksort(arr)
  return arr if arr.length <= 1

  pivot = arr.delete_at(rand(arr.length))
  left, right = arr.partition { |x| x < pivot }
  [*quicksort(left), pivot, *quicksort(right)]
end

def mergesort(arr)
  return arr if arr.length <= 1

  mid = arr.length / 2
  left = mergesort(arr[0...mid])
  right = mergesort(arr[mid..-1])
  merge(left, right)
end

def merge(left, right)
  sorted = []
  sorted << (left.first <= right.first ? left.shift : right.shift) until left.empty? || right.empty?
  sorted + left + right
end

def heapsort(arr)
  n = arr.length
  a = [nil] + arr

  (n / 2).downto(1) { |i| heapify(a, i, n) }

  while n > 1
    a[1], a[n] = a[n], a[1]
    n -= 1
    heapify(a, 1, n)
  end

  a.drop(1)
end

def heapify(a, i, n)
  loop do
    l = 2 * i
    r = l + 1
    j = i

    j = l if l <= n && a[l] > a[j]
    j = r if r <= n && a[r] > a[j]

    break if j == i

    a[i], a[j] = a[j], a[i]
    i = j
  end
end

def insertion_sort(arr)
  (1...arr.length).each do |i|
    key = arr[i]
    j = i - 1
    while j >= 0 && arr[j] > key
      arr[j + 1] = arr[j]
      j -= 1
    end
    arr[j + 1] = key
  end
  arr
end

start_time = Time.now

fibonacci(1000)
matrix_a = Array.new(100) { Array.new(100) { rand(100) } }
matrix_b = Array.new(100) { Array.new(100) { rand(100) } }
matrix_multiply(matrix_a, matrix_b)

array = Array.new(10_000) { rand(1_000) }
quicksort(array.dup)
mergesort(array.dup)
heapsort(array.dup)
insertion_sort(array.dup)

end_time = Time.now
puts "Elapsed time Ruby: #{end_time - start_time} seconds"
