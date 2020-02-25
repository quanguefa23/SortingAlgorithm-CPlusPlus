#include "libs.h"

char link[] = "result.csv";

int powDec(int n) {
	int res = 1;
	while (n-- > 0)
		res *= 10;
	return res;
}

void swap(int &a, int &b) {
	int t = b;
	b = a;
	a = t;
}

void createRandomArray(int *&a, int n, int k) {
	delete[]a;
	srand(time(0));
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = (int)((k + 1)*(rand() / (RAND_MAX + 1.0)) * (rand() / (RAND_MAX + 1.0)));
}

void createSortedArray(int *&a, int n, int k) {
	delete[]a;
	srand(time(0));
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = (int)((k + 1)*(rand() / (RAND_MAX + 1.0)) * (rand() / (RAND_MAX + 1.0)));
	quickSort(a, n);
}

void createReverseArray(int *&a, int n, int k) {
	delete[]a;
	srand(time(0));
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = (int)((k + 1)*(rand() / (RAND_MAX + 1.0)) * (rand() / (RAND_MAX + 1.0)));
	quickSort(a, n);
	int m = n / 2;
	for (int i = 0; i < m; i++)
		swap(a[i], a[n - 1 - i]);
}

void createAlmostSortedArray(int *&a, int n, int k) {
	delete[]a;
	srand(time(0));
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = (int)((k + 1)*(rand() / (RAND_MAX + 1.0)) * (rand() / (RAND_MAX + 1.0)));
	quickSort(a, n);
	int m = n / 100;
	for (int i = 0; i < m; i++)
		a[100*i] = (int)((k + 1)*(rand() / (RAND_MAX + 1.0)) * (rand() / (RAND_MAX + 1.0)));
}

bool checkSortedArray(int *a, int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}

void checkSort(int *&a, int n, int k, int type, void(*sortAlgorithm)(int*, int), char *name) {
	clock_t start, end;
	start = clock();
	sortAlgorithm(a, n);
	end = clock();
	double time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
	cout << "Algorithm: " << name << "\nType of input: " << type <<
		"\nSize of array: " << n << "\nTime using (ms): " << time << endl;
	cout << "Check: " << checkSortedArray(a, n) << endl;
}

void checkAndWriteSort(int *&a, int n, int k, void(*sortAlgorithm)(int*, int)) {
	clock_t start, end;
	start = clock();
	sortAlgorithm(a, n);
	end = clock();
	double time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

	FILE *f = fopen(link, "a");
	fseek(f, 0, SEEK_END);
	fprintf(f, ",%d", (int)time);
	fclose(f);
}

void writeSort(int *&a, int *n, int k, void(*sortAlgorithm)(int*, int), char *name, void(*create)(int*&, int, int)) {
	FILE *f = fopen(link, "a");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n%s", name);
	fclose(f);
	for (int i = 0; i < N; i++) {
		create(a, n[i], k);
		checkAndWriteSort(a, n[i], k, sortAlgorithm);
	}
	cout << name << " sort done!" << endl;
}

void run(int *&a, int *n, int k, void(*create)(int*&, int, int)) {
	/*writeSort(a, n, k, selectionSort, "Selection", create);
	writeSort(a, n, k, insertionSort, "Insertion", create);
	writeSort(a, n, k, binaryInsertionSort, "Binary Insertion", create);
	writeSort(a, n, k, bubbleSort, "Bubble", create);
	writeSort(a, n, k, shakerSort, "Shaker", create);*/
	writeSort(a, n, k, shellSort, "Shell", create);

	writeSort(a, n, k, heapSort, "Heap", create);
	writeSort(a, n, k, mergeSort, "Merge", create);
	writeSort(a, n, k, quickSort, "Quick", create);

	writeSort(a, n, k, radixSort, "Radix", create);
	writeSort(a, n, k, countingSort, "Counting", create);
	writeSort(a, n, k, flashSort, "Flash", create);
}

void sortWithRandomArray(int *&a, int *n, int k) {
	FILE *f = fopen(link, "a");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n\nRANDOM\nSize");
	for (int i = 0; i < N; i++) {
		fprintf(f, ",%d", n[i]);
	}
	fclose(f);
	run(a, n, k, createRandomArray);
}

void sortWithSortedArray(int *&a, int *n, int k) {
	FILE *f = fopen(link, "a");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n\nSORTED\nSize");
	for (int i = 0; i < N; i++) {
		fprintf(f, ",%d", n[i]);
	}
	fclose(f);
	run(a, n, k, createSortedArray);
}

void sortWithReverseArray(int *&a, int *n, int k) {
	FILE *f = fopen(link, "a");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n\nREVERSE\nSize");
	for (int i = 0; i < N; i++) {
		fprintf(f, ",%d", n[i]);
	}
	fclose(f);
	run(a, n, k, createReverseArray);
}

void sortWithAlmostSortedArray(int *&a, int *n, int k) {
	FILE *f = fopen(link, "a");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n\nALMOST SORTED\nSize");
	for (int i = 0; i < N; i++) {
		fprintf(f, ",%d", n[i]);
	}
	fclose(f);
	run(a, n, k, createAlmostSortedArray);
}