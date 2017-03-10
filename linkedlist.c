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

struct List{  // The main structure
    int *array;
    size_t count;
    size_t length;
};

struct List *listCreate();  // Prototypes
int *listAdd(struct List *list, int num);

int main(){
    struct List *list=listCreate();
    if(!list){  // Check if it was allocated successfully
        return 1;
    }
    for(int i=0;i<300;i++){  // Fill it using the add function
        listAdd(list, i);
    }
    printf("%d", list->count);  // Print the number of int's

    free(list->array);  // Free the allocated memory
    free(list);

    return 0;
}

struct List *listCreate(){
    struct List *list=malloc(sizeof(struct List));  // We will return a list so we allocate memory
    if(!list){  // Check if it was allocated successfully
        return NULL;
    }

    list->array=malloc(sizeof(int)*16);  // Allocate 16 int's in 'list->array'
    if(!list->array){  // Check if it was allocated successfully
        free(list);
        return NULL;
    }
    list->count=0;  // We start from the zeroth element
    list->length=16;  // The start length is going to be 16 elements and after we fill the space we will allocate another piece of memory

    return list;  // We return the list, that's why the return type of the function is 'struct List *'
}

int *listAdd(struct List *list, int num){  // We get where to store the int and the int's value
    if(list->count==list->length){  // If we have reached the maximum length of the struct, allocate
        list->array=realloc(list->array, list->length*2*sizeof(int));
        if(!list->array){  // Check if it was allocated successfully
            return NULL;
        }
        list->length*=2;  // We double the length after we allocate for next use
    }

    list->array[list->count]=num;  // This works as follows: 'arr[key]=value'
    list->count++;  // Increase the count(On the previous line it was the 'key')

    return list->array;
}




