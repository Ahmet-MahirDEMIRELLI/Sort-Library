#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(int argc, char *argv[]) {
	int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
	int i;

    sort(arr, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}