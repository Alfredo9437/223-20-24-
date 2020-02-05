#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "open_closer.h"

#define IN 1
#define OUT 0

int main(int argc, const char * argv[]){
    FILE * fin;
    FILE * fout;
    int  tabs = 0;
    int c;

    bool ok = openfiles(argc, argv, &fin, &fout, &tabs);
    
    if( ok == false){
        return 1;
    }

bool inside_quotes = OUT;
int quote_count = 0;
bool comment_state = OUT;
int count = 0;

    while( (c = fgetc(fin)) != EOF ){
        if(c == '\'' || c ==  '\"'){
            inside_quotes = IN;
            quote_count++;
            if(quote_count == 2){
                inside_quotes = OUT;
                quote_count = 0;
            }
        }

        if(inside_quotes == OUT){
            if( c == '/'){
                comment_state = IN;
                count++;
            if(count == 2){
                comment_state = OUT;
                count = 0;
            }
        }else if(comment_state == OUT){
            fputc(c, fout);
        }
    }
}

    closefiles(fin, fout);
    return 0;

}
