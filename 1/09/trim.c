#include <stdio.h>

/* Copy input into oputput replacing each string of one or more blanks
 * by a single blank.
 */
main()
{
        int c, nb;

        nb = 0;
        while ((c = getchar()) != EOF) {
                if (c == ' ') {
                        ++nb;
                } else {
                        if (nb > 0) {
                                putchar(' ');
                                nb = 0;
                        }
                        putchar(c);
                }
        }
}
