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
#define IBL  64 // Initial buffer length

char *ala();

char *ala(){
    char *line=malloc(IBL);
    if(!line){
        return NULL;
    }
    size_t i=0, length=IBL;
    char ch=getchar();
    while(ch!='\n' && ch!=EOF){      // EOF=End of file
        if(i==length-1){
            line=realloc(line, 2*length);
            // If you cannot realloc, set the 'i' bit to zero and return line
            if(!line){
                line[i]='\0';
                return line;
            }
            length*=2;
        }
        line[i]=ch;
        i++;
        ch=getchar();
    }
    line[i]='\0';

    return line;
}

int main(){
    char *line=ala();
    if(line){
        printf("\n%s\n", line);
        printf("Length: %lu\n", strlen(line));
    }
    free(line);

    return 0;
}
