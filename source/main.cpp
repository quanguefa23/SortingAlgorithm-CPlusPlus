#include "libs.h"

void main() {
	int *a = NULL, n[] = { 1000000, 2000000, 4000000, 6000000, 8000000, 10000000, 12000000, 14000000, 16000000, 20000000 };
	//int *a = NULL, n[] = { 100, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 2000 };
	int k = K;

	cout << "RANDOM\n" << endl;
	sortWithRandomArray(a, n, k);
	cout << "___________" << endl;

	cout << "\nSORTED" << endl;
	sortWithSortedArray(a, n, k);
	cout << "___________" << endl;

	cout << "\nREVERSE" << endl;
	sortWithReverseArray(a, n, k);
	cout << "___________" << endl;

	cout << "\nALMOST SORTED" << endl;
	sortWithAlmostSortedArray(a, n, k);
	cout << "___________" << endl;

	system("pause");	
}