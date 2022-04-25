#include <stdio.h>
#include <stdlib.h>

int isHeap_recursive(int arr[], int i, int n);
int isHeap_iter(int arr[], int n);

int main () {
    int n, *arr; 
    printf("How many entries? ");
    scanf("%d", &n);
    printf("Enter %d entries: ", n);

    arr = malloc(n * sizeof(int)); // it complained more with freeing than without it 

    for(int i = 0; i < n; i++) scanf("%d", arr + i);
    printf("Recursive says %s!\n", isHeap_recursive(arr, 0, n) ? "Yes":"No");
    printf("Iterative says %s!\n", isHeap_iter(arr, n) ? "Yes":"No");

    return 0;
}

int isHeap_recursive(int arr[], int i, int n) {
    if(i <= (n-2) / 2 ) {
	int parent, right, left;
	parent = i ? arr[(i - 1) / 2] : 0; // ternary here so no -1/2 action and malindexing
	right = arr[2 * i + 2];
	left = arr[2 * i + 1];

	if(parent > arr[i] || right < arr[i] || left < arr[i]) return 0;

	return isHeap_recursive(arr, 2 * i + 1, n) && isHeap_recursive(arr, 2*i + 2, n);
    }

    return 1;
}

int isHeap_iter(int arr[], int n) {
    int parent, left, right;
    for(int i = 0; i <= (n-2)/2; i++) {
	parent = i ? arr[(i - 1) / 2] : 0; // ternary here so no -1/2 action and malindexing
	right = arr[2 * i + 2];
	left = arr[2 * i + 1];
	if(parent > arr[i] || right < arr[i] || left < arr[i]) return 0;
    }

    return 1;
}
