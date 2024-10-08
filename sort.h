#ifndef SORT_H
#define SORT_H

// Function prototypes
void bubbleSortInt(int arr[], int n);
void insertionSortInt(int arr[], int n);
void selectionSortInt(int arr[], int n);
void quickSortInt(int arr[], int low, int high);
void mergeSortInt(int arr[], int l, int r);
void bucketSortFloat(float arr[], int n);

void sortInt(int arr[], int n);
void sortFloat(float arr[], int n);

// uncomplete
void shellSort(int arr[], int n);
void countingSort(int arr[], int n);
void heapSort(int arr[], int n);
void redixSort(int arr[], int n);
void timSort(int arr[], int n);
void treeSort(int arr[], int n);
void combSort(int arr[], int n);
void cubeSort(int arr[], int n);

#endif
