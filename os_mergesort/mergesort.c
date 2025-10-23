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

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){
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

