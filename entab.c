#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "open_closer.h"

int main(int argc, const char * argv[]){
    FILE * fin;
    FILE * fout;
    int  tabs = 0;
    int c;

    bool ok = openfiles(argc, argv, &fin, &fout, &tabs);
    
    if( ok == false){
        return 1;
    }

int space_counter = 0;
int t;
int s;

    while( (c = fgetc(fin)) != EOF ){
        if( c != ' '){
            fputc(c, fout);
        }else{
            space_counter = 1;
            while( (c = fgetc(fin)) != EOF && c == ' '){
                space_counter++;
            }
            t = (space_counter / tabs);
            s = (space_counter % tabs);
            for(int a = 0; a < t; a++){
                fputc('\t', fout);
            }
            for(int b = 0; b < s; b++){
                fputc(' ', fout);
            }
            fputc(c, fout);
        }
    }

    closefiles(fin, fout);
    return 0;

}