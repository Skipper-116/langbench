#!/bin/bash

# Build the C# project
dotnet build ./csharp/MyFirstProgram.csproj

# Compile the Java program
javac ./javaCode/Main.java

# Compile the C++ program
g++ -o cPlusPlus/main ./cPlusPlus/main.cpp

# Compile the C program
gcc -o cCode/program ./cCode/program.c

# Compile the Go program
go build -o goCode/main ./goCode/main.go

# Compile the Rust program using Cargo
cargo build --release --manifest-path ./rustCode/Cargo.toml

# Run the programs
dotnet run --project ./csharp
./rustCode/target/release/rustCode &
dart run dartCode/program.dart &
ruby ./rubyCode/sample.rb &
java -cp ./javaCode Main &
./cPlusPlus/main &
./cCode/program &
./goCode/main &
python ./pyCode/main.py &
node ./jsCode/index.js &
php ./phpCode/index.php &
wait