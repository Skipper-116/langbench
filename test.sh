#!/bin/bash

# Build the C# project
dotnet build ./csharp/MyFirstProgram.csproj

# Compile the Java program
javac ./javaCode/Main.java

# Compile the C++ program
g++ -o cPlusPlus/main ./cPlusPlus/main.cpp

# Compile the C program
gcc -o cCode/program ./cCode/program.c

# Run the programs
ruby ./rubyCode/sample.rb &
java -cp ./javaCode Main &
./cPlusPlus/main &
./cCode/program &
python ./pyCode/main.py &
node ./jsCode/index.js &
dotnet run --project ./csharp & 
wait