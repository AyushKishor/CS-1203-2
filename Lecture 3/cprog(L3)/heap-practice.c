#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int *xp, int *yp)
{   
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}

void heapInsert(int arr[], int n, int elm)
{
     int i, parent; 
     arr[n] = elm;
     i = n;

     if (i == 0) return;
   
     while (i != 0){
         parent = (i-1)/2;

         if (arr[parent] < arr[i]){ 
            // if parent < current element
           swap(&arr[i], &arr[parent]);

         }
         else break;
         i = parent;
    }
}

void heapify(int arr[], int n, int i){

    int largest, left, right, j;

    while(1){
      left = 2*i+1; right = 2*i+2; largest = i;
      if (left < n && arr[left] > arr[largest]){
         largest = left; 
         }
      if (right < n && arr[right] > arr[largest]) {
         largest = right; 
         }
      if (largest != i){
        swap(&arr[i], &arr[largest]);
        i = largest;
      }
      else break;
    }
}

int heapDelete(int arr[], int n, int *c1, int *c2)
{
     int i, left, right, largest, val, flag = 1;

     *c1 = 0; *c2 = 0;
     if (n == 0) return -9999;
     val = arr[0];
     arr[0] = arr[n-1];
     i = 0;

     while (flag == 1){
        flag = 0; largest = i;
        left = 2*i+1; right = 2*i+2;
         (*c1)++;
        if (left <= n-1 && arr[left] > arr[largest]){
                largest = left; flag = 1;
        }
         (*c1)++;
        if (right <= n-1 && arr[right] > arr[largest]){
                largest = right; flag = 1;
        }
        if (flag == 1){
                 (*c2)++;
                 swap(&arr[i], &arr[largest]); i = largest;
        }
     }
     return val;
}

int main()
{
    
}
