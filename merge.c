#include <stdio.h>
#include "merge.h"

void merge(FILE *wbfs, FILE *wbf1, FILE *resFile) {

    // check if ALL files exist and a new "WBFS/XXXXXX.wbfs" could be created
    if(wbfs == NULL || wbf1 == NULL || resFile == NULL) {
        puts("couldn't open files");
    
    } else {
        printf("Merging your files...\n");
        
        // read WBFS and WBF1 files and put their contents into new "WBFS/XXXXXX.wbfs"
        int buffer;

        while((buffer = fgetc(wbfs)) != EOF) { // while not "End Of File" (EOF) WBFS
            fputc(buffer, resFile);            // write these bits into "WBFS/XXXXXX.wbfs" 
        }

        while((buffer = fgetc(wbf1)) != EOF) {  // while not "End Of File" (EOF) WBF1
            fputc(buffer, resFile);             // append these bits into "WBFS/XXXXXX.wbfs" 
        }
    
        printf("Files successfuly merged. HAVE FUN!\n");

        // close files
        fclose(wbfs);
        fclose(wbf1);
        fclose(resFile);
    }
}