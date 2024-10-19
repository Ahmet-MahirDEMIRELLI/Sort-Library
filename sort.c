#include "sort.h"
#include <stdbool.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);
void swap(int *xp, int *yp); 

void bubbleSortInt(int arr[], int n) {
	bool swapped = true;
    int i = 0,j;
    while(i < n-1 && swapped){
    	swapped = false;
    	for(j = 0;j < n-1-i;j++){
    		if(arr[j] > arr[j+1]){
    			swap(&arr[j], &arr[j + 1]);
    			swapped = true;
			}
		}
		i++;
	}
}

void insertionSortInt(int arr[], int n) {
	int i,j,key;
	for(i = 1;i < n;i++){
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void insertionSortFloat(float arr[], int n) {
	int i,j;
	float key;
	for(i = 1;i < n; i++){
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void selectionSortInt(int arr[], int n) {
	int i,j,min_index;
	for(i = 0;i < n-1; i++){
		min_index = i;
		for(j = i+1;j < n;j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		if(i != min_index){
			swap(&arr[i], &arr[min_index]);
		}
	}
}

void quickSortInt(int arr[], int low, int high) {
	if(low < high){
		int pivot_index = partitionQuick(arr, low, high);
		quickSortInt(arr, low, pivot_index-1);
		quickSortInt(arr,pivot_index+1, high);
	}
}

int partitionQuick(int arr[], int low, int high){
	int pivot = arr[high], i = low, j;
	for(j = low;j <= high; j++){
		if(arr[j] < pivot){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}

void mergeSortInt(int arr[], int l, int r) {
	if(l < r){
		int m = (l + r) / 2;
		mergeSortInt(arr, l, m);
		mergeSortInt(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r){
	int i,j,k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int *left = (int *) malloc(n1 * sizeof(int));
	int *right = (int *) malloc(n2 * sizeof(int));
	
	for(i = 0; i < n1; i++){
		left[i] = arr[l+i];
	}
	for(j = 0; j < n2; j++){
		right[j] = arr[m+1+j];
	}
	
	i = 0; j = 0; k = l;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	
	while(j < n2){
		arr[k] = right[j];
		j++;
		k++;
	}
	free(left);
	free(right);
}

void bucketSortFloat(float arr[], int n){
	float **buckets = (float**) malloc(n * sizeof(float*));
	int* bucketSizes = (int*) malloc(n * sizeof(int));
	int i, j, k;

	for(i = 0; i < n; i++){
		buckets[i] = (float*) malloc(n * sizeof(float));
		bucketSizes[i] = 0;
	}

	for(i = 0; i < n; i++){
		j = (int)(n * arr[i]);
		buckets[j][bucketSizes[j]++] = arr[i];
	}

	for(i = 0; i < n; i++){
		insertionSortFloat(buckets[i], bucketSizes[i]);
	}

	k = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < bucketSizes[i]; j++){
			arr[k++] = buckets[i][j];
		}
		free(buckets[i]);
	}

	free(buckets);
	free(bucketSizes);
}

void shellSortInt(int arr[], int n){
	int gap, i, j, tmp;
	for (gap = n/2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
			tmp = arr[i];
			for(j = i; j >= gap && arr[j-gap] > tmp; j -=gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = tmp;
        }    
    }
}

// Function to sort the array, using merge sort as the default
void sortInt(int arr[], int n) {
    mergeSortInt(arr, 0,n-1);
}
// Function to sort the array, using bucket sort as the default
void sortFloat(float arr[], int n) {
    bucketSortFloat(arr,n);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}