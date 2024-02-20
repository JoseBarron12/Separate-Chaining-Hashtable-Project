# Hash Table Program

**Data Structure:**  Hash Table <BR>
**Programming Focus:** C++ development, construction of hash table using STL vector

## Overview

Welcome to the Hash Table Program! This C++ program implements a hash table with separate chaining and indirect sorting. The program allows users to insert records, search for records, and print the hash table entries. The hash table is implemented with a custom hash function, and duplicate keys are handled appropriately.

## Files

1. `htable.h` (given): Header file containing the class definition for the hash table.
2. `htable.cc`: Implementation file for the hash table class with member functions.
3. `entry.h` (given): Header file defining the structure of an entry in the hash table.
4. `hashmain.h` (given): Header file containing function prototypes and constants for the main program.
5. `hashmain.cc` (given): Main program file where users interact with the hash table.

## Hash Table Operations

The program supports the following operations:

- **Insert Record (`A`):** Inserts a new record into the hash table.
- **Search Record (`S`):** Searches for a record with a specified key in the hash table.
- **Print Hash Table (`P`):** Prints all active entries of the hash table.
- **Sorted Print (`P`):** Prints the hash table entries in sorted order based on the keys.

## Input Format

The program reads input from a file where each line represents a command or record. The commands are as follows:

- `A:key:num:description`: Insert a record with the given key, number, and description.
- `S:key`: Search for a record with the specified key.
- `P`: Print all active entries in the hash table.
- `S`: Print the sorted hash table.

## Sample Test Runs

Two sample test runs are provided: `hashsample01.in` and `hashsample02.in`, along with their corresponding expected output (`hashsample01.refout` and `hashsample02.refout`).

## Skills Showcase

This project showcases proficiency in several key areas:

### Programming Languages

- **C++:**
  - Utilizes C++ language features, including object-oriented principles, to implement the hash table program.
  - Demonstrates a solid understanding of C++ concepts such as classes, member functions, and file I/O.

### Data Structures

- **Hash Tables:**
  - Implements a hash table with separate chaining and indirect sorting.
  - Handles collisions and duplicate keys appropriately, showcasing an understanding of hash table design.

- **Linked Lists:**
  - Utilizes linked lists as part of the underlying data structure for separate chaining.

### Problem Solving

- **Algorithm Design:**
  - Designs and implements a custom hash function for efficient record insertion.
  - Implements sorting logic for displaying entries in sorted order.

- **Debugging:**
  - Ensures the program's correctness through thorough testing and debugging.

### Testing

- **Test Runs:**
  - Includes sample test runs with corresponding expected output.
  - Demonstrates the robustness and correctness of the hash table program.

These skills collectively showcase the ability to design, implement, and document a C++ program that effectively addresses the challenges of hash table implementation.

