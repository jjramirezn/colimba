#include <stdio.h>

main()
{
        int c;
        double nb, nt, nl;

        nb = nt = nl = 0.0;

        while ((c = getchar()) != EOF) {
                if (c == '\n')
                        ++nl;
                else if (c == '\t')
                        ++nt;
                else if (c == ' ')
                        ++nb;
        }
        printf("The input cointains:\n");
        printf("\t%.0f blanks.\n", nb);
        printf("\t%.0f tabs.\n", nt);
        printf("\t%.0f newlines.\n", nl);
}
