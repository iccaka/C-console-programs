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

    /*
        fob---->first opening bracket
        fcb---->first closing bracket
        sob---->second opening bracket
        scb---->second closing bracket
    */

char *ala(char *line);

char *ala(char *line){
        // If we type "<name>George</name":

        char *fob=strchr(line, '<'); // <name>George</name>
        if(!fob){
            return NULL;
        }
        char *fcb=strchr(fob+1, '>'); // >George</name>
        if(!fcb){
            return NULL;
        }
        char *sob=strstr(fcb+1, "</"); // </name>
        if(!sob){
            return NULL;
        }
        char *scb=strchr(sob, '>'); // >
        if(!scb){
            return NULL;
        }
            char *ft=fob+1; // name>George</name
            fcb[0]='\0';
            char *st=sob+2; // name>
            scb[0]='\0';
            int areEqual=strcmp(ft, st)==0;
            if(!areEqual){
                return NULL;
            }
            sob[0]='\0';
            char *data=fcb+1;
            ft[0]=toupper(ft[0]);
            char *result=malloc(strlen(ft)+strlen(data)+3);
            if(!result){
                return NULL;
            }
            sprintf(result, "%s: %s", ft, data);

            return result;
}
int main(){
    char *line=NULL;
    size_t size=0;
    getline(&line, &size, stdin);
    for(int i=0;i<3;i++){
        char *data=ala(line);
        if(!data){
            printf("Invalid format.\n");
        }
        else{
            printf("%s\n", data);
        }
        getline(&line, &size, stdin);
    }
    free(line);

    return 0;
}
