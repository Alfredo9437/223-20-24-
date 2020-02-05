#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define auto 10

bool openfiles(int argc, const char*argv[], FILE** fin, FILE** fout, int*n){

    if(argc < 3 || argc > 4){
        printf("Not enough parameters. Try again.\n" );
        return false;
    }

    *fin = fopen(argv[1], "r");
        *fout = fopen(argv[2], "w");

    if(*fin == NULL){
        return false; /*there was nothing to read*/
    }

    if(argc == 4){
        *n = atoi(argv[3]);
    }else{
        *n = auto;
    }

    return true;

}

void closefiles(FILE * fin, FILE * fout){
    fclose(fin);
    fclose (fout);
}