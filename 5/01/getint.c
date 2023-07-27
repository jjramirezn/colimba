#include <stdio.h>
#include <ctype.h>

#ifndef DEFGETINT
#define DEFGETINT
#define SIZE    1000
#define NOT_INT 0
int getch(void);
void ungetch(int);
int getint(int *pn);
#endif


/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as
 * a valid representation of zero. Fix it to push such a character back on the
 * input.
 */
int main(void)
{
        unsigned n, i;
        int res, array[SIZE];
        n = 0;
        while (n < SIZE - 1 && (res = getint(&array[n])) != EOF) {
                getch();                /* discard non digit */
                if (NOT_INT != res) {
                        ++n;
                }
        }
        printf("array = {\n");
        for (i = 0; i < n; ++i) {
                printf("\t%d,\n", array[i]);
        }
        putchar('}');
        putchar('\n');
        return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
        int c, sign;

        while (isspace(c = getch())) {
        }
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);     /* it's not a number */
                return NOT_INT;
        }
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-') {
                c = getch();
                if(!isdigit(c)) {
                        ungetch(c);
                        return NOT_INT;
                }
        }
        for (*pn = 0; isdigit(c); c = getch()) {
                *pn = 10 * *pn + (c - '0');
        }
        *pn *= sign;
        if (c != EOF) {
                ungetch(c);
        }
        return c;
}
