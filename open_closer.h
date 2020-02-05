#include <stdio.h>
#include "open_closer.c"

bool openfiles(int argc, const char*argv[], FILE**pfin, FILE**pfout, int*n);
void closefiles(FILE * fin, FILE *fout);