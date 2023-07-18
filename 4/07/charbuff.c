#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
        return (0 < bufp) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
        if (BUFSIZE <= bufp) {
                printf("ungetch: too many characters\n");
        } else {
                buf[bufp++] = c;
        }
}

void ungets(char s[]) {
        unsigned int i;
        for (i = strlen(s) - 1; 0 >= i; --i) {
                ungetch(s[i]);
        }
}
