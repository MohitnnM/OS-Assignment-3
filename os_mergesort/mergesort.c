/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
	int ls = leftstart;
	int rs = rightstart;
	int temp_index = ls;

	// merge the two subarrays into B
	while (ls <= leftend && rs <= rightend) {
		if (A[ls] <= A[rs]) {
			B[temp_index] = A[ls];
			temp_index++;
			ls++;
		} else {
			B[temp_index] = A[rs];
			temp_index++;
			rs++;
		}
	}

	// copy the remaining elements from the left subarray (if any)
	while (ls <= leftend) {
		B[temp_index] = A[ls];
		temp_index++;
		ls++;
	}

	// copy the remaining elements from the right subarray (if any)
	while (rs <= rightend) {
		B[temp_index] = A[rs];
		temp_index++;
		rs++;
	}

	// copy the merged elements from B back to A
	memcpy(A + leftstart, B + leftstart, (rightend - leftstart + 1) * sizeof(int));
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	my_mergesort(left, mid);
	my_mergesort(mid + 1, right);
	merge(left, mid, mid + 1, right);
}

void * parallel_mergesort(void *arg){
	struct argument *arg_struct = (struct argument *) arg;

	// hit base case: perform single threaded mergesort
	if (arg_struct->level >= cutoff) {
		my_mergesort(arg_struct->left, arg_struct->right);
		return NULL;
	}

	// find the mid index
	int mid = (arg_struct->left + arg_struct->right) / 2;

	// prepare arguments for left and right subarrays
	struct argument *left_arg = buildArgs(arg_struct->left, mid, arg_struct->level + 1);
	struct argument *right_arg = buildArgs(mid + 1, arg_struct->right, arg_struct->level + 1);

	// generate two threads to handle sub arrays
	pthread_t thread1, thread2;

	// safely create threads and pass argument to begin recursive mergesort calls
	if (pthread_create(&thread1, NULL, parallel_mergesort, left_arg) != 0) {
		perror("Failed to create thread 1 at level: " + arg_struct->level);
		exit(1);
	}
	if (pthread_create(&thread2, NULL, parallel_mergesort, right_arg) != 0) {
		perror("Failed to create thread 2 at level: " + arg_struct->level);
		exit(1);
	}

	// wait for both threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// merge the sorted subarrays
	merge(arg_struct->left, mid, mid + 1, arg_struct->right);

	// free the allocated argument structs
	free(left_arg);
	free(right_arg);

	return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
	// Instantiate a new argument struct
	struct argument *arg = (struct argument *) malloc(sizeof(struct argument));
	arg->left = left;
	arg->right = right;
	arg->level = level;

	return arg;
}

