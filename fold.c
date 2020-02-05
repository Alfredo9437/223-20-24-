#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "open_closer.h"

int main(int argc, const char * argv[]){
    FILE * fin;
    FILE * fout;
    int  limit = 0;
    int c;

    bool ok = openfiles(argc, argv, &fin, &fout, &limit);
    
    if( ok == false){
        return 1;
    }
int char_limit = limit;
int counter = 0;

    while( (c = fgetc(fin)) != EOF ){
        counter++;
        if(counter > char_limit){
            if(c == ' '){

            }else{
            fputc('\n', fout);
            fputc(c, fout);
            counter = counter - char_limit;
            }
            
        }else{
            fputc(c, fout);
        }

    }

    closefiles(fin, fout);
    return 0;

}