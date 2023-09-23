#include <stdio.h>
void swap(int *xp, int *yp)
{   
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}

void printArray(int arr[], int size)
{   
    int i; 
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heapify(int arr[], int n, int i){
    int largest, left, right, j;
    while(1){
      left = 2*i+1; right = 2*i+2; largest = i;

      if (left < n && arr[left] > arr[largest]) 
         largest = left;

      if (right < n && arr[right] > arr[largest]) 
         largest = right;

      if (largest != i){
        swap(&arr[i], &arr[largest]);
        i = largest;
      }
      else break;
    }
}

int main(){
    int arr[] = {110, 37, 73, 92, 19, 53, 77, 81, 99, 3};
    int n = 10, i;

        printf("Initial data:   ");
	printArray(arr, n);

        for (int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        printf("Heap structure: ");
	printArray(arr, n);
}
