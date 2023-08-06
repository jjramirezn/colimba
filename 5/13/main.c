#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail.h"

static char *lineptr[MAXLINES];

int main(int argc, char *argv[])
{
        unsigned long len;
        int j;
        int maxlines = 10;
        char *p, line[MAXLEN];
        int i = 0, maxed = 0, printed = 0;
        if (3 < argc) {
                printf("usage: tail [-n #]\n");
                return 1;
        }
        if (3 == argc) {
                if (strcmp("-n", argv[1]) == 0) {
                        maxlines = atoi(argv[2]);
                } else {
                        printf("tail: illegal option - %s\n", argv[1]);
                        printf("usage: tail [-n #]\n");
                        return 1;
                }
        } else if (2 == argc) {
                if (strncmp("-n", argv[1], 2) == 0) {
                        maxlines = atoi(argv[1]+2);
                } else {
                        printf("tail: illegal option - %s\n", argv[1]);
                        printf("usage: tail [-n #]\n");
                        return 1;
                }
        }
        if (maxlines <= 0) {
                return 0;
        }
        maxlines = maxlines < MAXLINES ? maxlines : MAXLINES;
        while ((len = getline2(line, MAXLEN)) > 0) {
                if (maxed) {
                        afree(strlen(lineptr[i]));
                }
                if ((p = alloc(len)) == NULL) {
                        printf("error: no more space in buffer\n.");
                        return 1;
                }
                line[len-1] = '\0';
                strcpy(p, line);
                lineptr[i++] = p;
                if (maxlines <= i) {
                        i = 0;
                        maxed = 1;
                }
        }
        j = maxed ? i : 0;
        while (printed++ < (maxed ? maxlines : i)) {
                printf("%s\n", lineptr[j]);
                j = j < maxlines - 1 ? j + 1 : 0;
        }
        return 0;
}
