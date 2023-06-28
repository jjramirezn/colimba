#include <stdio.h>

#define NEWLINE 0
#define WORD    1
#define BLANK   2

#define MAXSTR  1000

int main()
{
        int c, nb ,state;
        char bstr[MAXSTR];

        nb = 0;
        state = NEWLINE;
        while ((c = getchar()) != EOF) {
                if (c == '\n' && state != NEWLINE) {
                        state = NEWLINE;
                        putchar(c);
                        nb = 0;
                        bstr[0] = '\0';
                } else if (c == ' ' || c == '\t') {
                        state = BLANK;
                        if (nb < MAXSTR-1) {
                                bstr[nb] = c;
                                ++nb;
                        } else if (nb == MAXSTR-1)
                                ++nb;
                } else if (c != '\n') {
                        if (state == BLANK) {
                                bstr[nb] = '\0';
                                printf("%s", bstr);
                        }
                        state = WORD;
                        putchar(c);
                        nb = 0;
                        bstr[0] = '\0';
                }
        }
        return 0;
}
