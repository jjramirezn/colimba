#include <limits.h>
#include <stdio.h>

#define IN  1
#define OUT 0

main()
{
        int c, i, j, nc, state, max;
        int nlen[10];

        state = OUT;
        nc = 0;
        for (i = 0; i < 10; ++i)
                nlen[i] = 0;

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' ||  c == '\t') {
                        if (nc >= 10)
                                ++nlen[9];
                        else
                                ++nlen[nc-1];
                        nc = 0;
                        state = OUT;
                } else {
                        ++nc;
                        state = IN;
                }
        }
        /* for the last word */
        if (nc >= 10)
                ++nlen[9];
        else if (nc > 0)
                ++nlen[nc-1];

        max = INT_MIN;
        for (i = 0; i < 10; ++i)
                if (nlen[i] > max)
                        max = nlen[i];
        if (max > 0)
                for (i = 0; i < 10; ++i)
                        nlen[i] = nlen[i] * 20 / max;          /* normalize */


        printf("|------------------------------|\n");
        for (i = 20; i >= 0; --i) {
                putchar('|');
                for (j = 0; j < 10; ++j) {
                        if (nlen[j] >= i)
                                printf("===");
                        else
                                printf("   ");
                }
                printf("|\n");
        }
        printf("|------------------------------|\n");
        printf("| 1  2  3  4  5  6  7  8  9 +10|\n");
        printf("|------------------------------|\n");
}

