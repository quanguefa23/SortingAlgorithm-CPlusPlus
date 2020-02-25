#pragma once
#include <iostream>
#include <time.h>
#include <cstdlib> 
#define K 200000
#define N 10
#define RANDOM 0
#define SORTED 1
#define SORTED_IN_REVERSE 2
#define ALMOST_SORTED 3
using namespace std;

#include "type1.h"
#include "type2.h"
#include "type3.h"

//supported function
int powDec(int n);
void createRandomArray(int *&a, int n, int k);
void createSortedArray(int *&a, int n, int k);
void createReverseArray(int *&a, int n, int k);
void createAlmostSortedArray(int *&a, int n, int k);
void swap(int &a, int &b);
bool checkSortedArray(int *a, int n);

void checkSort(int *&a, int n, int k, int type, void(*sortAlgorithm)(int*, int), char *name);
void checkAndWriteSort(int *&a, int n, int k, void(*sortAlgorithm)(int*, int));
void writeSort(int *&a, int *n, int k, void(*sortAlgorithm)(int*, int), char *name, void(*create)(int*&, int, int));
void run(int *&a, int *n, int k, void(*create)(int*&, int, int));
void sortWithRandomArray(int *&a, int *n, int k);
void sortWithSortedArray(int *&a, int *n, int k);
void sortWithReverseArray(int *&a, int *n, int k);
void sortWithAlmostSortedArray(int *&a, int *n, int k);