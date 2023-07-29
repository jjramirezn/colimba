#include <stdio.h>
#include <time.h>
#include "sortlines.h"

#define BUFFSIZE 10000

static char *lineptr[MAXLINES];
static char buff[BUFFSIZE];

/* sort input lines */
int main(void)
{
        clock_t start, end;
        int nlines, rcode;

        start = clock();
        if ((nlines = readlinesarr(lineptr, MAXLINES, buff, BUFFSIZE)) >= 0) {
        /*
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        */
                qsort(lineptr, 0, nlines-1);
                writelines(lineptr, nlines);
                rcode = 0;
        } else {
                printf("error: input too big to sort\n");
                rcode = 1;
        }
        end = clock();
        printf("Used %lu ticks or %.3e seconds\n", end - start, ((double) (end - start)) / CLOCKS_PER_SEC);
        return rcode;
}
