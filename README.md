# LangBench: Cross-Language Performance Benchmarking

Welcome to LangBench! This project aims to benchmark the performance of various programming languages by running a Fibonacci calculation and matrix multiplication. Our goal is to provide a comprehensive comparison of execution times across different languages and encourage contributions from the developer community.

## Why LangBench?

- **Comprehensive**: Compare multiple languages in one place.
- **Open Source**: Contribute and improve the benchmarks.
- **Up-to-Date**: Regularly updated with the latest language versions.
- **Community-Driven**: Collaborate with developers worldwide.

## Getting Started

### How to Run the Benchmark

1. Clone the repository:
    ```sh
    git clone https://github.com/Skipper-116/langbench.git
    cd langbench
    ```

2. Ensure you have the required versions of each language installed on your system.

3. Run the `test.sh` script from the terminal:
    ```sh
    sh test.sh
    ```

### Language Versions

The following language versions are used in this project:

- **C++**: Apple clang version 16.0.0 (clang-1600.0.26.4)
- **C#**: .NET 9.0.100
- **Java**: OpenJDK 17
- **Ruby**: ruby 3.2.0 (2022-12-25 revision a528908271) [arm64-darwin23]

## Project Structure

- `./cPlusPlus/main.cpp`: Contains the C++ implementation of the Fibonacci calculation and matrix multiplication.
- `./cSharp/Program.cs`: Contains the C# implementation of the Fibonacci calculation and matrix multiplication.
- `./javaCode/Main.java`: Contains the Java implementation of the Fibonacci calculation and matrix multiplication.
- `./rubyCode/sample.rb`: Contains the Ruby implementation of the Fibonacci calculation and matrix multiplication.
- `test.sh`: Script to run the benchmarks for each language.

## Example Output

After running the `test.sh` script, you will see output similar to the following:

```sh
Elapsed time C++: 0.00001002 seconds
Elapsed time C#: 0.00001503 seconds
Elapsed time Java: 0.00001234 seconds
Elapsed time Ruby: 0.00001345 seconds
```

## Requirements
Make sure you have the following installed on your system:

* C++ compiler (Apple clang version 16.0.0 or compatible)
* .NET 9.0.100
* OpenJDK 21.0.3
* ruby 3.2.0 (2022-12-25 revision a528908271) [arm64-darwin23]