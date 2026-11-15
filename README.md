*This project has been created as part of the 42 curriculum by adeestev.*

## Description
C++ Module 09 is the final capstone module of the C++ curriculum, focusing on advanced data management, algorithm efficiency, and container usage within the C++98 standard. Moving away from standard academic classes, this module challenges you to solve complex, real-world data processing problems using appropriate Standard Template Library (STL) containers and algorithms under strict performance and architectural constraints.

## Exercises Overview

* **Exercise 00: Bitcoin Exchange**

Requires the implementation of a program that evaluates the value of a Bitcoin at a given date. It parses a database (data.csv) containing historical exchange rates and processes an input file containing dates and values. The solution must efficiently look up dates (using appropriate STL associative containers like std::map), handle closest-date matching for missing entries, and thoroughly validate inputs (such as positive numbers, valid date formats, and value limits).

* **Exercise 01: RPN (Reverse Polish Notation)**

Focuses on evaluating mathematical expressions written in Reverse Polish Notation. The program takes an expression as an argument, processes it using a Last-In, First-Out (LIFO) data structure (such as std::stack), and computes the final result. It must properly manage operator precedence, handle single-digit operands, and throw explicit errors for invalid syntax or division by zero.

* **Exercise 02: PmergeMe (Ford-Johnson Algorithm)**

A performance-heavy exercise requiring the implementation of the Ford-Johnson merge-insertion sort algorithm. The program must sort a sequence of positive integers passed as command-line arguments and compare the execution efficiency across two different STL containers (such as std::vector and std::deque). It requires robust parsing, careful memory/container management, and formatted output displaying the sort time comparisons.

## Instructions

Each exercise is located within its own directory (ex00 to ex02) and must be compiled independently.

* **Compiler:** c++

* **Compilation Flags:** -Wall -Wextra -Werror -std=c++98

* **Execution:** Navigate to the respective directory and run make to build the executable. Run the generated binary to observe the container behaviors and algorithm outputs.

## Resources

* **Documentation:** C++98 standard references for STL containers (std::map, std::stack, std::vector, std::deque), algorithms, and the Ford-Johnson merge-insertion sorting algorithm.
