## Assignment 3 Concurrency

* Authors: Mohit Mittal, Riley Lienert
* Group name: Pair Group 1

## Overview

This program implements a parallel merge sort algorithm that utilises multi-threading to speed up sorting time. It achieves this by recursively dividing the array into subarrays, sorting them (in parallel up to a cutoff level) and then merging the results back together to produce a fully ordered array.

## Manifest

**Mergesort.c -** Contains the implementations of the sequential and parallel versions of the merge sort algorithm, my_mergesort and parallel_mergesort, utilising pthreads. Does the merging, recursions and manages threads. 

**Mergesort.h -** Is the header file for mergesort.c, containing the global variables, structures and function prototypes all used in mergersort.c.

**Makefile -** This file defines how to compile and link this program, also cleaning any generated files when run.

**test-mergesort.c -** This file is used to test the program. When run, it sets up the array, the cutoff level and calls the merge sort functions. 

## Building the project
It is a straightforward process to build this project simply:

1. Run:
```
make
```
in the terminal. Compiles the program, linking it into an executable file called **test-mergesort**

2. If you want to regenerate and test it again, run:
   -  ```make clean``` in the terminal (cleans all generated files).
   - ```make``` again to compile the .c files.

## Features and usage
**Features:**

1. Contains the implementations of both the sequential and parallel versions of mergesort.
   
2. Subarrays are sorted in parallel through the use of pthreads to multiple threads.
   
3. Implements a cutoff level, thus allowing you to control the number of levels that utilise threading.

4. Subarrays are automatically merged after threads are complete.

 **Usage:**

To run this program, after building simply execute:
```
./test-mergesort <array_size> <cutoff_level>
```
**Arguments:**

<array_size> = the number of integers to be sorted.

<cutoff_level> = the depth of recursion where you want parallelism to stop.
 

## Testing

The following tests were run to ensure the correctness and performance of the program:

1. Small arrays ~10-100 elements:
   - Used to test the correctness of the program.
   - Printed the arrays before and after sorting for verification.
   - Ensured output matched the expected results.
2. Edge cases:
   - Testing the correctness of the code.
   - Tested using arrays of size 1 and 0, which the program handled well.
   - Tested using arrays containing duplicates, negative integers, or values already sorted.
4. Sequential vs Parallel versions:
   - Testing the correctness of the code.
   - Compared the results of both versions of merge sort using identical inputs, ensuring that the resultant output was the same.

**Performance**

1. Measured the run time of the program with larger inputs (~100,000+ integers).
2. Consistent speedups were observed in parallel execution, mainly when the cutoff levels were between 2-4.

## Known Bugs

No known bugs exist in this program

## Reflection and Self Assessment

During development, the main challenge was understanding how the provided template and functions interacted. This required carefully reading the specification, analysing the starter code, and reviewing merge sort concepts through the background section and reference materials. Once the basic merge sort logic was understood, implementing the sequential version was straightforward.

Adding parallelism was initially unfamiliar but became clear after revisiting the textbook sections on concurrency and the use of pthread_create and pthread_join. With the provided data structure for passing thread arguments, implementing multithreading mainly involved managing thread creation, synchronisation, and merging results correctly.

Most issues arose from small implementation mistakes such as forgetting to free dynamically allocated argument structures and mistakenly using a while loop instead of an if statement for the cutoff condition. After identifying and correcting these errors through testing and code review, the program ran efficiently. Overall, the process went smoothly, and understanding how recursive functions interact with threads was a key concept that “clicked” during this project. Testing also exceeded expectations, with the multi-threaded implementation producing a 4 times speedup, further validating success.

## Sources Used

The primary resource used in this assignment was the youtube video 'Algorithms: Merge Sort' (https://youtu.be/KF2j-9iSf4Q) which was featured in the assignment description. This explained the inner workings of the standard merge sort alogrithm and how to implement it in code. Overall, the general structure was followed when implementing our custom approach. Secondly, the textbook's (Operating Systems: Three Easy Pieces) concurrency chapter was read to understand pthreads and how to use the library.
