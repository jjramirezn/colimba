#include <stdio.h>

#define IN  1
#define OUT 0

main()
{
        int c, i, j, nc, state;
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

        for (i = 0; i < 9; ++i) {
                printf("%d   |", i+1);
                for (j = 0; j < nlen[i]; ++j)
                        putchar('|');
                putchar('\n');
        }
        printf("+10 |");
        for (j = 0; j < nlen[9]; ++j)
                putchar('|');
        putchar('\n');
}
