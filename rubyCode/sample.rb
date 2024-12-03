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

start_time = Time.now

fibonacci(1000)
matrix_a = Array.new(100) { Array.new(100) { rand(100) } }
matrix_b = Array.new(100) { Array.new(100) { rand(100) } }
matrix_multiply(matrix_a, matrix_b)

end_time = Time.now
puts "Elapsed time Ruby: #{end_time - start_time} seconds"
