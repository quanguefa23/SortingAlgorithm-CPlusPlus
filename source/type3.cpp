#include "type3.h"

//1. Counting Sort
int findMax(int *a, int n) {
	int res = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > res)
			res = a[i];
	return res;
}

int findMin(int *a, int n) {
	int res = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < res)
			res = a[i];
	return res;
}

void countingSort(int *a, int n) {
	int max = findMax(a, n);

	int *f = new int[max + 1], i;
	for (i = 0; i <= max; i++)
		f[i] = 0;
	for (i = 0; i < n; i++)
		f[a[i]]++;

	for (i = 1; i <= max; i++)
		f[i] += f[i - 1];

	int *b = new int[n];
	for (i = 0; i < n; i++) {
		b[f[a[i]] - 1] = a[i];
		f[a[i]]--;
	}

	for (i = 0; i < n; i++)
		a[i] = b[i];

	delete[]f;
	delete[]b;
}

//2. Radix Sort

int digit(int a, int k) {
	for (int i = 0; i < k - 1; i++)
		a /= 10;
	return a % 10;
}

void sort(int *a, int n, int k) {
	int *f = new int[10], i, j;

	for (i = 0; i < 10; i++)
		f[i] = 0;
	for (i = 0; i < n; i++)
		f[digit(a[i], k)]++;
	for (i = 1; i < 10; i++)
		f[i] += f[i - 1];

	int *b = new int[n];
	for (i = n - 1; i >= 0; i--) {
		j = digit(a[i], k);
		b[f[j] - 1] = a[i];
		f[j]--;
	}

	for (i = 0; i < n; i++)
		a[i] = b[i];

	delete[]f;
	delete[]b;
}

void radixSort(int *a, int n) {
	int max = findMax(a, n), d = 1;
	while ((max /= 10) > 0)
		d++;

	for (int i = 1; i <= d; i++)
		sort(a, n, i);
}

//3. Flash Sort
void flashSort(int *a, int n) {
	//1. Divide array into m sector
	int max = findMax(a, n), min = findMin(a, n);
	int m = (int)(0.43 * n), i, k;
	double c = (m - 1.0) / (max - min);
	int *L = new int[m];

	for (i = 0; i < m; i++)
		L[i] = 0;
	for (i = 0; i < n; i++) {
		k = (int)((a[i] - min) * c);
		L[k]++;
	}
	L[0]--;
	for (i = 1; i < m; i++)
		L[i] += L[i - 1];

	//2. Category each number to the right sector
	int count = 0, t;
	k = m - 1;
	i = 0;
	while (count < n) {
		while (i > L[k]) {
			i++;
			k = (int)((a[i] - min) * c);
		}
		while (i <= L[k]) {
			k = (int)((a[i] - min) * c);
			t = a[L[k]];
			a[L[k]] = a[i];
			a[i] = t;
			L[k]--;
			count++;
		}
	}

	//3. Sort in each sector
	int j;
	for (k = 1; k < m; k++) {
		for (i = L[k] - 1; i > L[k - 1]; i--) {
			if (a[i] > a[i + 1]) {
				t = a[i];
				j = i;
				while (t > a[j + 1])
					a[j++] = a[j + 1];
				a[j] = t;
			}
		}
	}
}
