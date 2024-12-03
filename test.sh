#!/bin/bash

# Build the C# project
dotnet build ./csharp/MyFirstProgram.csproj

# Compile the Java program
javac ./javaCode/Main.java

# Compile the C++ program
g++ -o cPlusPlus/main ./cPlusPlus/main.cpp

# Run the programs
dotnet run --project ./csharp & 
ruby ./rubyCode/sample.rb &
java -cp ./javaCode Main &
./cPlusPlus/main &
wait