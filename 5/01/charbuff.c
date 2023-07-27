#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

static int ch = -1;

int getch(void) /* get a (possibly pushed back) character */
{
        if (ch < 0) {
                return getchar();
        } else {
                char c = ch;
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
