#include "type1.h"
#include "libs.h"

//1. Selection Sort
void selectionSort(int *a, int n) {
	int count = n - 1, max, imax;
	while (count) {
		max = a[count];
		imax = count;
		for (int i = 0; i < count; i++)
			if (a[i] > max) {
				max = a[i];
				imax = i;
			}
		a[imax] = a[count];
		a[count--] = max;
	}
}

//2. Insertion Sort
void insertionSort(int *a, int n) {
	int t, j;
	for (int i = 1; i < n; i++) {
		j = i - 1;
		t = a[i];
		while (j >= 0 && t < a[j])
			a[j + 1] = a[j--];
		a[j + 1] = t;
	}
}

//3. Binary Insertion Sort 
int binarySearch(int a[], int item, int low, int high) {
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;
	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

void binaryInsertionSort(int *a, int n) {
	int i, loc, j, selected;

	for (i = 1; i < n; ++i) {
		j = i - 1;
		selected = a[i];
		loc = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space 
		while (j >= loc) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

//4. Bubble Sort
void bubbleSort(int *a, int n) {
	int count = n, i, flag = 0;
	while (--count) {
		flag = 0;
		for (i = 0; i < count; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = 1;
			}
		}
		if (!flag)	break;
	}
}

//5. Shaker Sort
void shakerSort(int *a, int n) {
	int m = n / 2, i, j;
	bool flag = 0;
	for (i = 0; i < m; i++) {
		flag = 0;
		for (j = n - 1 - i; j > i; j--)
			if (a[j] < a[j - 1]) {
				flag = 1;
				swap(a[j], a[j - 1]);
			}
		for (j = i + 1; j < n - 1 - i; j++)
			if (a[j] > a[j + 1]) {
				flag = 1;
				swap(a[j], a[j + 1]);
			}
		if (!flag) break;
	}
}

//6. ShellSort
void shellSort(int *a, int n) {
	int h = 1, t, i, j;
	while (h < n / 3)
		h = 3 * h + 1;
	while (h > 0) {
		for (i = h; i < n; i++) {
			t = a[i];
			j = i;
			while (j > h - 1 && a[j - h] > t) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = t;
		}
		h = (h - 1) / 3;
	}
}