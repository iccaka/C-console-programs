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
    FILE *file=fopen("image.jpg", "r");  // Open the image
    if(!file){  // Check if it was oppened correctly
        return 1;
    }

    fseek(file, 0, SEEK_END);  // Go to the end of the file
    long long pos=ftell(file);  // Tell me how long the file is
    fseek(file, 0, SEEK_SET);  // Go back at the beginning of the file
    long long partSize=(pos/5)+1;  // We want to make 5 parts
    char buffer[4096];  // Create a buffer

    for(int i=0;i<5;i++){
        char name[12];
        sprintf(name, "Part-%lu.jpg", i+1);
        FILE *currFile=fopen(name, "w");  // Open the file 'Part-1.jpg' with 'w' attribute (It does not exist, so create it) 
        if(!currFile){  // Check if it was created successfully
            return 1;
        }

        size_t writtenBytes=0;
        while(writtenBytes<=partSize && !feof(currFile)){  // While we are not at the end of the file, do...
            size_t readBytes=fread(buffer, 1, 4096, file);  // Read 4096 bytes from 'file'("image.jpg"), and store them into 'buffer'
            fwrite(buffer, 1, readBytes, currFile);  // Get the buffer and put it into the newly created file 'Part-1.jpg'
            writtenBytes+=readBytes;  // Increase 'writtenBytes'
        }
        fclose(currFile); // Close both the main and the new files
    }
    fclose(file);

    return 0;
}
