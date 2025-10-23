## Assignment 3 Concurrency

* Authors: Mohit Mittal, Riley Lienert
* Group name: Pair Group 1

## Overview

This program implements a parallel merge sort algorithm that utilises multi-threading to speed up sorting time. It achieves this by recursively diving the array into subarrays, sorting them (in parallel up to a cutoff level) and then merging the results back together to produce a fully ordered array.

## Manifest

A listing of source files and other non-generated files, and a brief
(one-line) explanation of the purpose of each file.

## Building the project

This section should tell the user how to build your code.  If you are
delivering a library, where does it need to be installed, or how do you use
it? Is this an executable, if so, how can a user get up to speed as fast as
possible?

## Features and usage

Summarise the main features of your program. It is also appropriate to
instruct the user how to use your program.

## Testing

This section should detail how you tested your code. Simply stating "I ran
it a few times and it seems to work" is not sufficient. Your testing needs
to be detailed here.

## Known Bugs

No known bugs exist in this program

## Reflection and Self Assessment

During development, the main challenge was understanding how the provided template and functions interacted. This required carefully reading the specification, analysing the starter code, and reviewing merge sort concepts through the background section and reference materials. Once the basic merge sort logic was understood, implementing the sequential version was straightforward.

Adding parallelism was initially unfamiliar but became clear after revisiting the textbook sections on concurrency and the use of pthread_create and pthread_join. With the provided data structure for passing thread arguments, implementing multithreading mainly involved managing thread creation, synchronisation, and merging results correctly.

Most issues arose from small implementation mistakes such as forgetting to free dynamically allocated argument structures and mistakenly using a while loop instead of an if statement for the cutoff condition. After identifying and correcting these errors through testing and code review, the program ran efficiently. Overall, the process went smoothly, and understanding how recursive functions interact with threads was a key concept that “clicked” during this project. Testing also exceeded expectations, with the multi-threaded implementation producing a 4 times speedup, further validating success.

## Sources Used

The primary resource used in this assignment was the youtube video 'Algorithms: Merge Sort' (https://youtu.be/KF2j-9iSf4Q) which was featured in the assignment description. This explained the inner workings of the standard merge sort alogrithm and how to implement it in code. Overall, the general structure was followed when implementing our custom approach. Secondly, the textbook's (Operating Systems: Three Easy Pieces) concurrency chapter was read to understand pthreads and how to use the library.
