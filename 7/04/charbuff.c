#include <stdio.h>
#include <string.h>

static int ch = -1;

int getch(void) /* get a (possibly pushed back) character */
{
        char c;
        if (ch < 0) {
                return getchar();
        } else {
                c = ch;
                ch = -1;
                return c;
        }
}

void ungetch(int c)     /* push character back on input */
{
        if (ch < 0) {
                ch = c;
        } else {
                printf("ungetch: too many characters\n");
        }
}

void startbuff() {
        ch = -1;
}
