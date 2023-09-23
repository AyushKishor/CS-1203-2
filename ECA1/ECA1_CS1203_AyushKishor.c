#include <stdio.h>

// Swap two integers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Reverse the array from 'start' to 'end'
void reverse(int arr[], int start, int end) {
  while (start < end) {
    swap(&arr[start], &arr[end]);
    start++;
    end--;
  }
}

// Function to generate the next permutation in lexicographic order
int next_permutation(int arr[], int n) {
  int i = n - 2;

  // Find the first element which is smaller than its next element
  while (i >= 0 && arr[i] >= arr[i + 1]) {
    i--;
  }

  // If no such element found, we have reached the last permutation
  if (i < 0) {
    return 0;
  }

  int j = n - 1;
  // Find the smallest element greater than arr[i] to the right of arr[i]
  while (arr[j] <= arr[i]) {
    j--;
  }

  // Swap the elements
  swap(&arr[i], &arr[j]);

  // Reverse the sequence after index i to get the next lexicographic
  // permutation
  reverse(arr, i + 1, n - 1);

  return 1;
}

int main() {
  int n;
  printf("Enter a value for n: ");
  scanf("%d", &n);

  if (n <= 0 || n > 8) {
    printf("Please provide a valid input for n (1 ≤ n ≤ 8).\n");
    return 1;
  }

  // Initialize the array with values from 1 to n
  int arr[8];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  // Start with the initial permutation and keep generating the next one until
  // possible
  do {
    for (int i = 0; i < n; i++) {
      printf("%d", arr[i]);
      if (i < n - 1) {
        printf(",");
      }
    }
    printf("\n");
  } while (next_permutation(arr, n)); // Keep generating next permutation

  return 0;
}
