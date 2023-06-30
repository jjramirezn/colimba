#include <stdio.h>

#define HEIGHT 20

/* 1-13 Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 */
int main()
{
        int c, i, j, nc, max;
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

        max = nlen[0];
        for (i = 1; i < 10; ++i) {
                if (nlen[i] > max) {
                        max = nlen[i];
                }
        }
        if (max > 0) {
                for (i = 0; i < 10; ++i) {
                        nlen[i] = nlen[i] * HEIGHT / max;       /* normalize */
                }
        }


        printf("|------------------------------|\n");
        for (i = HEIGHT; i >= 0; --i) {
                putchar('|');
                for (j = 0; j < 10; ++j) {
                        printf(nlen[j] >= i ? "===" : "   ");
                }
                printf("|\n");
        }
        printf("|------------------------------|\n");
        printf("| 1  2  3  4  5  6  7  8  9 +10|\n");
        printf("|------------------------------|\n");
        return 0;
}

