// https://en.wikipedia.org/wiki/Quicksort
#include <iostream>
#include <time.h>
#include <cstdlib>
#define LEN 100

using namespace std;

int partition(int A[], int lo, int hi);

void quicksort(int A[], int lo, int hi) {
	if (lo < hi) {
		int p = partition(A, lo, hi);
		quicksort(A, lo, p - 1);
		quicksort(A, p + 1, hi);
	}
}

int partition(int A[], int lo, int hi) {
	int pivot = A[hi];
	int i = lo;
	for (int j = lo; j < hi; j++) {
		if (A[j] <= pivot) {
			swap(A[i], A[j]);
			i = i + 1;
		}
	}
	swap(A[i], A[hi]);
	return i;
}

int main() {
	int A[LEN];

	srand(time(NULL));
	for (int i = 0; i < LEN; i++) {
		A[i] = rand() % 100;
	}

	quicksort(A, 0, LEN-1);

	for (int i = 0; i < LEN; i++) {
		cout << A[i] << " ";
	}
	
	return 0;
}
