#include "sort.h"
#include <stdbool.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);
void swap(int *xp, int *yp); 

void bubbleSort(int arr[], int n) {
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

void insertionSort(int arr[], int n) {
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

void selectionSort(int arr[], int n) {
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

void quickSort(int arr[], int low, int high) {
	if(low < high){
		int pivot_index = partitionQuick(arr, low, high);
		quickSort(arr, low, pivot_index-1);
		quickSort(arr,pivot_index+1, high);
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

void mergeSort(int arr[], int l, int r) {
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
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

// Function to sort the array, using selection sort as the default
void sort(int arr[], int n) {
    mergeSort(arr, 0,n-1);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}