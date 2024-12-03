# frozen_string_literal: true

def fibonacci(num:, memo: {})
  return num if num <= 1
  return memo[num] if memo.key?(num)

  memo[num] = fibonacci(num: (num - 1), memo: memo) + fibonacci(num: (num - 2), memo: memo)
  memo[num]
end

def matrix_multiply(a, b)
  result = Array.new(a.length) { Array.new(b[0].length, 0) }
  a.length.times do |i|
    b[0].length.times do |j|
      b.length.times do |k|
        result[i][j] += a[i][k] * b[k][j]
      end
    end
  end
  result
end

start_time = Time.now

fibonacci(num: 1000, memo: {})
matrix_a = Array.new(100) { Array.new(100) { rand(100) } }
matrix_b = Array.new(100) { Array.new(100) { rand(100) } }
matrix_multiply(matrix_a, matrix_b)

end_time = Time.now
puts "Elapsed time Ruby: #{end_time - start_time} seconds"
