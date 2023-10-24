#include <stdio.h>
#include <stdlib.h>


void swap(int *aPTR, int *bPTR){
    int temp = *aPTR;
    *aPTR = *bPTR;
    *bPTR = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[],  int length){
    int flag = 1;
    while(flag != 0){
        flag = 0;
        for (int i = 0; i < length; i++){
        if(arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            flag = 1;
        }
        
    }

    }
    
}






int main(){
    int a = 10;
    int b = 5;

    swap(&a,&b);

    printf("a= %d \n b= %d \n",a, b);
    int arr[] = {2,5,1,7,10,34,62,8,90};
    

    printArray(arr,9);
    return 0;
}