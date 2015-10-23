// https://en.wikipedia.org/wiki/Binary_search_algorithm
#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#define LEN 100

using namespace std;

int binary_search(int A[], int key, int imin, int imax) {
	if (imax < imin) {
		return -1;
	}

	int imid = imin + (imax - imin) / 2;
	if (A[imid] > key) {
		binary_search(A, key, imin, imid-1);
	}
	else if (A[imid] < key) {
		binary_search(A, key, imid+1, imax);
	}
	else {
		return imid;
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
