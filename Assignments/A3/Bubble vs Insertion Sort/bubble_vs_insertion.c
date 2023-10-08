#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int temp;
    *comparisons = 0;
    *swaps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *comparisons, int *swaps) {
    int key, j;
    *comparisons = 0;
    *swaps = 0;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j+1] = arr[j];
            j = j - 1;
            (*swaps)++;
        }
        arr[j+1] = key;
    }
}

int main() {
    srand(time(0));
    int comparisons, swaps;
    int totalComparisonsBubble = 0, totalSwapsBubble = 0;
    int totalComparisonsInsertion = 0, totalSwapsInsertion = 0;

    for (int k = 0; k < 100; k++) {
        int arr1[10], arr2[10];
        for (int i = 0; i < 10; i++) {
            arr1[i] = rand() % 100;
            arr2[i] = arr1[i]; 
        }

        bubbleSort(arr1, 10, &comparisons, &swaps);
        totalComparisonsBubble += comparisons;
        totalSwapsBubble += swaps;

        insertionSort(arr2, 10, &comparisons, &swaps);
        totalComparisonsInsertion += comparisons;
        totalSwapsInsertion += swaps;
    }

    printf("Bubble Sort - Average Comparisons: %d, Average Swaps: %d\n", totalComparisonsBubble/100, totalSwapsBubble/100);
    printf("Insertion Sort - Average Comparisons: %d, Average Swaps: %d\n", totalComparisonsInsertion/100, totalSwapsInsertion/100);

    return 0;
}
