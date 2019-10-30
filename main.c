#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "print-usage.h"
#include "merge.h"

int main(int argc, char *argv[]) {
    FILE *wbfs;                 // split WBFS file
    FILE *wbf1;                 // split WBF1 foçe
    FILE *resFile;              // merged WBFS file that will be generated
    char resFilePath[1024];     // path to merged WBFS file that will be generated
    char id[7];                 // game id passed trough "--id"

    char wbfsFilename[1024];    // split WBFS file name
    char wbf1Filename[1024];    // split WBF1 file name

    char cwd[1024];             // directory where user called this program from
    char dir[10];               // absolute path to "WBFS" folder that will be created if not exits

    // get dir where user called this program from
    getcwd(cwd, sizeof(cwd));

    // handle arguments
    if(argc == 2) {
        
        if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h")  == 0)) { // if user types "wbfs-merge-cli --help" or "wbfs-merge-cli -h"
            print_usage();

        } else if(strstr(argv[1], ".wbfs") != NULL) { // if the only argument is the WBFS file as in "wbfs-merge-cli RGHJ52.wbfs"
            
            // generate WBFS and WBF1 file names
            strcpy(wbfsFilename, argv[1]);
            strcpy(wbf1Filename, argv[1]);

            wbf1Filename[strlen(wbf1Filename) - 1] = '1';
            
        } else { // if second parameter is NEITER "--help", "--h", "XXXXXX.wbfs" 
            printf("You must specify a WBFS file\n");
            print_usage();
        }

    } else if(argc == 3) {

        if(strcmp(argv[1], "--id") == 0) { // if 1st param is "--id"
            strcpy(id, argv[2]);

            // convert game id into UPPERCASE
            int i = 0;
            while(id[i] != '\0') {
                if(id[i] >= 'a' && id[i] <= 'z') {
                    id[i] = id[i] - 32;
                }
                i++;
            }

            // generate WBFS and WBF1 file names
            strcpy(wbfsFilename, id);
            strcat(wbfsFilename, ".wbfs");

            strcpy(wbf1Filename, id);
            strcat(wbf1Filename, ".wbf1");

        }
        
    } else {
        print_usage();
    }

    // "main" function scope \\
    
    // make a string with full path to "WBFS" folder that will be created if not exists
    strcpy(dir, cwd);
    strcat(dir, "/WBFS");

    mkdir(dir, 0777);
    strcpy(resFilePath, "WBFS/");
    strcat(resFilePath, wbfsFilename);

    // set files to merge
    wbfs = fopen(wbfsFilename, "r");
    wbf1 = fopen(wbf1Filename, "r");
    resFile = fopen(resFilePath, "w");


    printf("preparing to merge \"%s\" and \"%s\" into \"%s\"\n", wbfsFilename, wbf1Filename, resFilePath);
    
    

    // call method "merge" from file "merge.c"
    merge(wbfs, wbf1, resFile);

    return 0;
}