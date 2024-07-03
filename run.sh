#!/bin/bash

# Check if the program number is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <program_number>"
  echo "Example: $0 1054"
  exit 1
fi

# Assign the program number
NUMBER=$1
FOLDER=$NUMBER

# Check if the .cpp file exists
if [ ! -f "$FOLDER/$NUMBER.cpp" ]; then
  echo "Error: $FOLDER/$NUMBER.cpp not found!"
  exit 1
fi

# Check if the .in file exists
if [ ! -f "$FOLDER/$NUMBER.in" ]; then
  echo "Error: $FOLDER/$NUMBER.in not found!"
  exit 1
fi

# Compile the .cpp file
echo "Compiling $FOLDER/$NUMBER.cpp"
g++ -o "$FOLDER/$NUMBER.o" "$FOLDER/$NUMBER.cpp"

# Check if the compilation was successful
if [ $? -ne 0 ]; then
  echo "Compilation failed!"
  exit 1
fi

# Run the program with input and save the output
echo "Running the program with input $FOLDER/$NUMBER.in"
echo "Output will be written to $FOLDER/$NUMBER.out"
./"$FOLDER/$NUMBER.o" < "$FOLDER/$NUMBER.in" > "$FOLDER/$NUMBER.out"

# Check if the program ran successfully
if [ $? -ne 0 ]; then
  echo "Program execution failed!"
  exit 1
fi

echo "Execution completed successfully. Output is in $NUMBER.out"
