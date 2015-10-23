// https://en.wikipedia.org/wiki/Merge_sort
#include <iostream>
#include <time.h>
#include <cstdlib>
#define LEN 100

using namespace std;

void TopDownSplitMerge(int A[], int iBegin, int iEnd, int B[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void CopyArray(int B[], int iBegin, int iEnd, int A[]);

void TopDownMergeSort(int A[], int B[], int n) {
	TopDownSplitMerge(A, 0, n, B);
}

void TopDownSplitMerge(int A[], int iBegin, int iEnd, int B[]) {
	if (iEnd - iBegin < 2) {
		return;
	}

	int iMiddle = (iEnd + iBegin) / 2;
	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	TopDownMerge(A, iBegin, iMiddle, iEnd, B);
	CopyArray(B, iBegin, iEnd, A);
}

void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]) {
	int i0 = iBegin, i1 = iMiddle;

	for (int j = iBegin; j < iEnd; j++) {
		if (i0 < iMiddle && (i1 >= iEnd || A[i0] <= A[i1])) {
			B[j] = A[i0];
			i0 = i0 + 1;
		}
		else {
			B[j] = A[i1];
			i1 = i1 + 1;
		}
	}
}

void CopyArray(int B[], int iBegin, int iEnd, int A[]) {
	for (int k = iBegin; k < iEnd; k++) {
		A[k] = B[k];
	}
}

int main() {
	int A[LEN];
	int B[LEN];

	srand(time(NULL));
	for (int i = 0; i < LEN; i++) {
		A[i] = rand() % 100;
	}

	TopDownMergeSort(A, B, LEN);

	for (int i = 0; i < LEN; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	
	return 0;
}
