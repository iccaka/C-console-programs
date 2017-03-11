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

int ala(char arr[], int start, int finish){  // Recursive string reverse
     if(start<finish){
        char swap=arr[start];
        arr[start]=arr[finish];
        arr[finish]=swap;
        ala(arr, ++start, --finish);
    }
}

int main(){
    char arr[]="Hello buddy!";
    ala(arr, 0, strlen(arr)-1);
    printf("%s", arr);

    return 0;
}
