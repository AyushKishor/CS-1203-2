#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons, swaps;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
    swaps++;
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            swaps++;
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
        swaps++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        swaps++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        comparisons++;
        if (arr[l] > arr[largest])
            largest = l;
    }
    if (r < n) {
        comparisons++;
        if (arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(0));
    int n = 10;
    int totalComparisonsMerge = 0, totalSwapsMerge = 0;
    int totalComparisonsQuick = 0, totalSwapsQuick = 0;
    int totalComparisonsHeap = 0, totalSwapsHeap = 0;

    for (int k = 0; k < 100; k++) {
        int arr1[n], arr2[n], arr3[n];
        for (int i = 0; i < n; i++) {
            int val = rand() % 100;
            arr1[i] = val;
            arr2[i] = val;
            arr3[i] = val;
        }

        comparisons = swaps = 0;
        mergeSort(arr1, 0, n-1);
        totalComparisonsMerge += comparisons;
        totalSwapsMerge += swaps;

        comparisons = swaps = 0;
        quickSort(arr2, 0, n-1);
        totalComparisonsQuick += comparisons;
        totalSwapsQuick += swaps;

        comparisons = swaps = 0;
        heapSort(arr3, n);
        totalComparisonsHeap += comparisons;
        totalSwapsHeap += swaps;
    }

    printf("Merge Sort - Avg Comparisons: %d, Avg Swaps: %d\n", totalComparisonsMerge/100, totalSwapsMerge/100);
    printf("Quick Sort - Avg Comparisons: %d, Avg Swaps: %d\n", totalComparisonsQuick/100, totalSwapsQuick/100);
    printf("Heap Sort - Avg Comparisons: %d, Avg Swaps: %d\n", totalComparisonsHeap/100, totalSwapsHeap/100);

    return 0;
}
