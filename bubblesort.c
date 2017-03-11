#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

void bubbleSort(int array[], int size, int(*comp)(int, int)){   // Bubble sort with function pointers.
    int swapped=1;
    while(swapped){
        swapped=0;
        for(int i=0; i<size-1;i++){
            if((*comp)(array[i], array[i+1])){
                int oldValue=array[i];
                array[i]=array[i+1];
                array[i+1]=oldValue;
                swapped=1;
            }
        }
    }
}
int desc(int a, int b){
    return a<b;
}
int asc(int a, int b){
    return a>b;
}
int main(){
    int arr[]={5,7,-1,-4,10,23,4,17,-17};
    int size=sizeof(arr)/sizeof(int);
    bubbleSort(arr, size, &desc);
    for(int i=0;i<size-1;i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
