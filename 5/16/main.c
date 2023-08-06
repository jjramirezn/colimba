#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "qsort.h"

char *lineptr[MAXLINES];        /* pointers to text lines */

int strdircmp(char *s, char*t);
int strcasedircmp(char *s, char*t);

/* sort input lines */
int main(int argc, char *argv[])
{
        int nlines;             /* number of input lines read */
        int i;
        char numeric = 0;       /* 1 if numeric sort */
        char reverse = 0;
        char casesen = 1;
        char dircmp = 0;
        CompF comp;

        for (i = 1; i < argc; ++i) {
                if (strcmp(argv[i], "-n") == 0) {
                        numeric = 1;
                } else if (strcmp(argv[i], "-r") == 0) {
                        reverse = 1;
                } else if (strcmp(argv[i], "-f") == 0) {
                        casesen = 0;
                } else if (strcmp(argv[i], "-d") == 0) {
                        dircmp = 0;
                } else {
                        printf("qsort: illegal option - %s\n", argv[i]);
                        printf("usage: qsort [-n] [-r]\n");
                        return 1;
                }
        }
        if (numeric) {
                comp = (CompF) numcmp;
        } else if (dircmp) {
                comp = casesen ? (CompF) strdircmp : (CompF) strcasedircmp;
        } else {
                comp = casesen ? (CompF) strcmp : (CompF) strcasecmp;
        }
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
                qsort((void **) lineptr, 0, nlines-1, comp);
                writelines(lineptr, nlines, reverse);
                return 0;
        } else {
                printf("input too big to sort\n");
                return 1;
        }
}

int dircmp(char *s, char *t, char casesen)
{
        while (!('\0' == *s || isalnum(*s) || isspace(*s))) {
                s++;
        }
        while (!('\0' == *s || isalnum(*t) || isspace(*t))) {
                t++;
        }
        for ( ; casesen ? *s == *t : tolower(*s) == tolower(*t); s++, t++) {
                while (!('\0' == *s || isalnum(*s) || isspace(*s))) {
                        s++;
                }
                while (!('\0' == *s || isalnum(*t) || isspace(*t))) {
                        t++;
                }
                if (*s == *t && *s == '\0') {
                        return 0;
                }
        }
        return *s - *t;
}

int strdircmp(char *s, char *t) {
        return dircmp(s, t, 1);
}

int strcasedircmp(char *s, char *t) {
        return dircmp(s, t, 0);
}
