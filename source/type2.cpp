#include "type2.h"
#include "libs.h"

//1. Heap Sort
void shift(int *a, int l, int r) {
	int i = l, j = 2 * i + 1;
	while (j <= r) {
		if (j < r && a[j] < a[j + 1])
			j++;
		if (a[i] >= a[j])
			break;
		swap(a[i], a[j]);
		i = j;
		j = 2 * i + 1;
	}
}

void heapSort(int *a, int n) {
	int l = (n - 2) / 2;
	while (l >= 0)
		shift(a, l--, n - 1);

	int r = n - 1;
	while (r > 0) {
		swap(a[0], a[r]);
		shift(a, 0, --r);
	}
}

//2. Quick Sort
void runQuickSort(int *a, int l, int r)
{
	int i = l, j = r;
	int pivot = a[(l + r) / 2];
	while (i <= j)
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (l < j) runQuickSort(a, l, j);
	if (i < r) runQuickSort(a, i, r);
}

void quickSort(int *a, int n) {
	runQuickSort(a, 0, n - 1);
}

//3. Merge Sort

void merge(int *a, int l, int m, int r) { //array1: l to m, array2: m + 1 to r
	int s1 = m - l + 1, s2 = r - m;
	int flag1 = l, flag2 = m + 1, i = 0;
	int *sub = new int[s1 + s2];

	while (i < s1 + s2) {
		if (flag1 <= m && flag2 <= r)
			sub[i++] = a[flag1] < a[flag2] ? a[flag1++] : a[flag2++];
		else if (flag1 > m)
			sub[i++] = a[flag2++];
		else sub[i++] = a[flag1++];
	}

	for (i = 0; i < s1 + s2; i++)
		a[l + i] = sub[i];
	delete[] sub;
}

void runMergeSort(int *a, int l, int r) {
	if (l == r)
		return;

	int m = (l + r) / 2;
	runMergeSort(a, l, m);
	runMergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

void mergeSort(int *a, int n) {
	runMergeSort(a, 0, n - 1);
}