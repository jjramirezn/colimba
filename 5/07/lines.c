#include <stdio.h>
#include <string.h>
#include "sortlines.h"

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
        int len, nlines;
        char *p, line[MAXLINES];

        nlines = 0;
        while ((len = getline2(line, MAXLEN)) > 0) {
                if (maxlines <= nlines || (p = alloc(len)) == NULL) {
                        return -1;
                } else {
                        line[len-1] = '\0';     /* delete newline */
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                }
        }
        return nlines;
}

/* readlinesarr: read input lines without using alloc*/
int readlinesarr(char *lineptr[], int maxlines, char *buff, int buffsize)
{
int len, nlines;
        char *p, line[MAXLINES];

        nlines = 0;
        p = buff;
        while ((len = getline2(line, MAXLEN)) > 0) {
                if (maxlines <= nlines || buffsize < p - buff + len) {
                        return -1;
                } else {
                        line[len-1] = '\0';     /* delete newline */
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                        p += len;
                }
        }
        return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
        while (0 < nlines--) {
                printf("%s\n", *lineptr++);
        }
}

/* getline2: read a line into s, return length; if the length is greater than
 *      the limit truncate the line but still report the correct length*/
unsigned long getline2(char s[], unsigned long lim)
{
        int c;
        unsigned long i;

        for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
                s[i] = c;
        }
        if (c == '\n') {
                s[i++] = c;
                s[i] = '\0';
        } else {
                s[i] = '\0';
                while ((c=getchar()) != EOF && c !='\n') {
                        ++i;
                }
        }
        return i;
}
