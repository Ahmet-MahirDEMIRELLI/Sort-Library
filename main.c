// gcc main.c sort.c -o program
// run program.exe
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void printIntArr(int [], int);
void printFloatArr(float [], int);

int main(int argc, char *argv[]) {
	int arr1[] = {64, 25, 12, 22, 11};
    float arr2[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n1 = 5;
    int n2 = 10;
	int i;

    sortInt(arr1, n1);
    printIntArr(arr1,n1);

    //sortFloat(arr2,n2);
    //printFloatArr(arr2,n2);

    system("pause");
    return 0;
}

void printIntArr(int arr[], int n){
    int i;
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printFloatArr(float arr[], int n){
    int i;
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}