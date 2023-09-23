#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void heapInsert(int arr[], int n, int elm, int *c1, int *c2)
// 
{
     int i, parent; 

     *c1 = 0; *c2 = 0;
     arr[n] = elm;
     i = n;

     if (i == 0) return;
   
     while (i != 0){
         parent = (i-1)/2;
         (*c1)++;
         if (arr[parent] < arr[i]){ 
           swap(&arr[i], &arr[parent]);
           (*c2)++;
         }
         else break;
         i = parent;
    }
}

int main()
{
    int arr[100000];
    int n = 100, i, comparisonCount, swapCount, t;
    double cc, sc;

    srand(time(NULL));
    
    for (n = 10000; n <= 100000; n = n+10000){
      cc = 0.0, sc = 0.0;
      for (t = 0; t < 100; t++){
        for (i = 0; i < n; i++)
	    arr[i] = rand()%10000;

        for(i = 0; i < n; i++){
            heapInsert(arr, i, arr[i], &comparisonCount, &swapCount);
	    cc += (double) comparisonCount;
	    sc += (double) swapCount;
        }
      }
      printf("n = %6d, %lf %lf\n", n, cc/(n*100.0), sc/(n*100.0));
     }
}
