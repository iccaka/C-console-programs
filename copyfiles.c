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
#include "header.h"
#include "header2.h"
#define BUFFER_SIZE 4096

void copy(const char *, const char *);  // The prototypes
void kill(const char *);

int main(){
    copy("text.txt", "text2.txt");  // Copy the first one into the second one

    return 0;
}

void copy(const char *srcPath, const char *destPath){
    FILE *srcFile=fopen(srcPath, "r");  // Open the source file
    if(!srcFile){  // Check if it was opened correctly
        kill(NULL);
    }
    FILE *destFile=fopen(destPath, "w");  // Open the destination file
    if(!destFile){  // Check if it was opened correctly
        kill(NULL);
    }
    char buffer[BUFFER_SIZE];  // Make a buffer
    while(!feof(srcFile)){  // While the source file is not at the EOF
        size_t bytesRead=fread(buffer, 1, BUFFER_SIZE, srcFile);  // Put the read information in 'buffer', maximum length = 'BUFFER_SIZE' and read from 'srcFile'
        fwrite(buffer, 1, bytesRead, destFile);  // Get 'buffer' and put it in 'destFile'(write only the needed bytes - 'bytesRead', that were read from the reading)
    }

    fclose(srcFile);  // Now free both the source and the destination file
    fclose(destFile);
}

void kill(const char *msg){  // Basically this is and error handling function
    if(errno){
        perror(msg);
    }
    else{
        fprintf(stderr, msg);
    }

    exit(1);
}
