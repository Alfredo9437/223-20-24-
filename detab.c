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

int counter;
int spaces_left;
char space = ' ';
    while( (c = fgetc(fin)) != EOF ){
        if(isalpha(c) || c == '-'){
            fputc(c, fout);
            counter++;

        }else if(counter != 0){
            if( c == ' ' || c == '.' || c == '!' || c== '?'){
                fputc(c, fout);
            }
            if( c == '\t'){
                spaces_left = tabs - counter;
                for(int i = 0; i < spaces_left; i++){
                    fputc(space, fout);
                }
            }
            counter = 0;
        }
    }

    closefiles(fin, fout);
    return 0;

}