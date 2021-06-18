#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000 // Length of each line in input file.

int main(int argc, char *argv[])
{ 
    char *strFileName = argv[1];
    char *strFileSummary = "sort_c_file.txt";
    char strTempData[MAX_LEN];
    char **strData = NULL; // String List
    int i, j;
    int noOfLines = 0;

    FILE * ptrFileLog = NULL;
    FILE * ptrSummary = NULL;

    if ( (ptrFileLog = fopen(strFileName, "r")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileName);
        return 1;
    }
    if ( (ptrSummary = fopen(strFileSummary, "a")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n",strFileSummary);
        return 1;
    }

    // Read and store in a string list.
    while(fgets(strTempData, MAX_LEN, ptrFileLog) != NULL) {
        // Remove the trailing newline character
        if(strchr(strTempData,'\n'))
            strTempData[strlen(strTempData)-1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**)*(noOfLines+1));
        strData[noOfLines] = (char*)calloc(MAX_LEN,sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        //printf("%s\n", strData[noOfLines]);
        noOfLines++;
    }

    char delim[] = " ";
    char *ptr1, *ptr2;
    char cpy1[1000], cpy2[1000]; 
    // Sort the array.
    for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {

            strcpy(cpy1, strData[j]);
            strcpy(cpy2, strData[j+1]);
            
            ptr1 = strtok(cpy1, delim);
            ptr2 = strtok(cpy2, delim);

            if (atoi(ptr1)>atoi(ptr2)) {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    // Write it to outfile. file.
    for(i = 0; i < noOfLines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);

    // free each string
    for(i = 0; i < noOfLines; i++)
        free(strData[i]);
        
    // free string list.
    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);
    return 0;
}