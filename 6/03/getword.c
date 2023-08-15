#include <ctype.h>
#include <stdio.h>
#include "wordcount.h"

enum {
        OUT,
        IN
};

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
        int c;
        int i = 0;
        char *w = word;
        char state = OUT;
        while ((c = getch()) != EOF) {
                if (OUT == state) {
                        if ('\n' == c) {
                                ungetch(c);
                                return 1;
                        } else if (!isspace(c)) {
                                ungetch(c);
                                state = IN;
                        }
                } else if (IN == state) {
                        if (lim <= 0) {
                                break;
                        } else if (isspace(c)) {
                                ungetch(c);
                                break;
                        } else {
                                w[i++] = c;
                                --lim;
                        }
                } else {
                        printf("getword: illegal state %d", state);
                        break;
                }
        }
        w[i] = '\0';
        return i;
}
