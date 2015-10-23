// https://en.wikipedia.org/wiki/Binary_search_algorithm
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#define LEN 100

using namespace std;

int binary_search(int A[], int key, int iBegin, int iEnd) {
	if (iEnd - iBegin < 2) {
		return -1;
	}

	int iMiddle = iBegin + (iEnd - iBegin) / 2;
	if (A[iMiddle] > key) {
		binary_search(A, key, iBegin, iMiddle-1);
	}
	else if (A[iMiddle] < key) {
		binary_search(A, key, iMiddle+1, iEnd);
	}
	else {
		return iMiddle;
	}
}

int main() {
	int A[LEN];

	srand(time(NULL));
	for (int i = 0; i < LEN; i++) {
		A[i] = rand() % 100;
	}

	sort(A, A+LEN);

	for (int i = 0; i < LEN; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	
	cout << binary_search(A, 73, 0, LEN-1) << endl;

	return 0;
}
