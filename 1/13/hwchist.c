#include <stdio.h>

/* 1-13 Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 */
int main()
{
        int c, i, j, nc;
        int nlen[10];

        nc = 0;
        for (i = 0; i < 10; ++i) {
                nlen[i] = 0;
        }

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' ||  c == '\t') {
                        if (nc > 0) {
                                ++nlen[nc >= 10 ? 9 : nc-1];
                        }
                        nc = 0;
                } else {
                        ++nc;
                }
        }
        /* for the last word */
        if (nc > 0) {
                ++nlen[nc >= 10 ? 9 : nc-1];
        }

        for (i = 0; i < 9; ++i) {
                printf("%d   |", i+1);
                for (j = 0; j < nlen[i]; ++j) {
                        putchar('|');
                }
                putchar('\n');
        }
        printf("+10 |");
        for (j = 0; j < nlen[9]; ++j) {
                putchar('|');
        }
        putchar('\n');
        return 0;
}
