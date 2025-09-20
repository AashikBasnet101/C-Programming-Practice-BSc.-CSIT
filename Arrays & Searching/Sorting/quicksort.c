//Quicksort (recursive)
#include <stdio.h>

void swap(int *a, int *b){ int t=*a; *a=*b; *b=t; }

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j=low;j<high;j++) {
        if (arr[j] <= pivot) { i++; swap(&arr[i], &arr[j]); }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}

int main() {
    int n; printf("n: "); if (scanf("%d", &n)!=1) return 0;
    int a[n];
    for (int i=0;i<n;i++) scanf("%d", &a[i]);
    quicksort(a, 0, n-1);
    printf("Sorted: ");
    for (int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
