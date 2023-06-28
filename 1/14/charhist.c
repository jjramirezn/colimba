#include <stdio.h>

#define ALPHABET_LEN 26
#define HISTY        20

void printcell(int qty, int lvl) {
        if (qty >= lvl)
                printf("===");
        else
                printf("   ");
}

main()
{
        int c, i, j, max, ndig, noth, nb;
        int nchar[ALPHABET_LEN];

        ndig = noth = nb = 0;
        for (i = 0; i < ALPHABET_LEN; ++i)
                nchar[i] = 0;

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' ||  c == '\t')
                        ++nb;
                else if (c >= '0' && c <= '9')
                        ++ndig;
                else if (c >= 'a' && c <= 'z') {
                        c = c - 32;     /* to upper case */
                        ++nchar[c - 'A'];
                } else if (c >= 'A' && c <= 'Z')
                        ++nchar[c - 'A'];
                else
                        ++noth;
        }

        max = ndig;
        if (noth > max)
                max = noth;
        if (nb > max)
                max = nb;
        for (i = 0; i < ALPHABET_LEN; ++i)
                if (nchar[i] > max)
                        max = nchar[i];
        if (max > 0) {
                ndig = ndig * HISTY / max;
                noth = noth * HISTY / max;
                nb = nb * HISTY / max;
                for (i = 0; i < ALPHABET_LEN; ++i)
                        nchar[i] = nchar[i] * HISTY / max;          /* normalize */
        }


        printf("|---------------------------------------------------------------------------------------|\n");
        for (i = HISTY; i >= 0; --i) {
                putchar('|');
                for (j = 0; j < ALPHABET_LEN; ++j) {
                        printcell(nchar[j], i);
                }
                printcell(ndig, i);
                printcell(nb, i);
                printcell(noth, i);
                printf("|\n");
        }
        printf("|---------------------------------------------------------------------------------------|\n");
        putchar('|');
        for (i = 0; i < ALPHABET_LEN; ++i)
                printf(" %c ", i + 'A');
        printf("0-9");
        printf("Wts");
        printf("Oth|\n");
        printf("|---------------------------------------------------------------------------------------|\n");
}

