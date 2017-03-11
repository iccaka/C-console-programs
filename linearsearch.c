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

int main(){
    int arr[]={1,2,3,4,5,6,8,9,10}, a;  // Linear search
    printf("Enter a number:\n");
    scanf("%d", &a);
    int size=sizeof(arr)/sizeof(int);
    for(int i=0;i<size-1;i++){
        if(a==arr[i]){
            printf("Yes.");
            return 0;
        }
    }
    printf("No");

    return 0;
}
