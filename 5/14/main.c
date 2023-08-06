#include <stdio.h>
#include <string.h>
#include "qsort.h"

char *lineptr[MAXLINES];        /* pointers to text lines */

/* sort input lines */
int main(int argc, char *argv[])
{
        int nlines;             /* number of input lines read */
        int i;
        char numeric = 0;       /* 1 if numeric sort */
        char reverse = 0;

        for (i = 1; i < argc; ++i) {
                if (strcmp(argv[i], "-n") == 0) {
                        numeric = 1;
                } else if (strcmp(argv[i], "-r") == 0) {
                        reverse = 1;
                } else {
                        printf("qsort: illegal option - %s\n", argv[i]);
                        printf("usage: qsort [-n] [-r]\n");
                        return 1;
                }
        }
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
                qsort((void **) lineptr, 0, nlines-1,
                        numeric ? (CompF) numcmp : (CompF) strcmp);
                writelines(lineptr, nlines, reverse);
                return 0;
        } else {
                printf("input too big to sort\n");
                return 1;
        }
}

