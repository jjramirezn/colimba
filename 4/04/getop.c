#include <ctype.h>
#include <stdio.h>
#include "enums.h"

enum states {
        START,
        SKIP,
        NEGATIVE,
        INTEGER,
        DOT,
        FRACTIONAL,
        T,
        TO,
        D,
        DU,
        S,
        SW,
        C,
        CL
};

int getch(void);
void ungetch(int);
char low(char);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
        int i, c, state;
        state = START;

        i = 0;
        c = getch();
        while (1) {
                switch (state) {
                case START:
                        if (isdigit(c)) {
                                s[i++] = c;
                                state = INTEGER;
                        } else if (c == '-') {
                                s[i++] = '-';
                                state = NEGATIVE;
                        } else if (c == '.') {
                                s[i++] = '0';
                                s[i++] = '.';
                                state = DOT;
                        } else if (c == ' ' || c == '\t') {
                                state = SKIP;
                        } else if (low(c) == 't') {
                                state = T;
                        } else if (low(c) == 'd') {
                                state = D;
                        } else if (low(c) == 's') {
                                state = S;
                        } else if (low(c) == 'c') {
                                state = C;
                        } else {
                                return c;
                        }
                        break;
                case SKIP:
                        while ((c = getch()) == ' ' || c == '\t') {
                        }
                        state = START;
                        break;
                case NEGATIVE:
                        c = getch();
                        if (isdigit(c)) {
                                s[i++] = c;
                                state = INTEGER;
                        } else if (c == '.') {
                                s[i++] = '0';
                                s[i++] = '.';
                                state = DOT;
                        } else {
                                if (c != EOF) {
                                        ungetch(c);
                                }
                                return '-';
                        }
                        break;
                case INTEGER:
                        while (isdigit(s[i++] = c = getch())) {
                        }
                        if (c == '.') {
                                state = DOT;
                        } else {
                                s[--i] = '\0';
                                if (c != EOF) {
                                        ungetch(c);
                                }
                                return NUMBER;
                        }
                        break;
                case DOT:
                        c = getch();
                        if (isdigit(c)) {
                                state = FRACTIONAL;
                        } else {
                                s[--i] = '\0';
                                if (c != EOF) {
                                        ungetch(c);
                                }
                                return NUMBER;
                        }
                        break;
                case FRACTIONAL:
                        while (isdigit(s[i++] = c = getch())) {
                        }
                        s[--i] = '\0';
                        if (c != EOF) {
                                ungetch(c);
                        }
                        return NUMBER;
                        break;
                case T:
                        c = getch();
                        if (low(c) == 'o') {
                                state = TO;
                        } else {
                                printf("error: unknown command t%c\n", c);
                                state = SKIP;
                        }
                        break;
                case TO:
                        c = getch();
                        if (low(c) == 'p') {
                                return TOP;
                        } else {
                                printf("error: unknown command to%c\n", c);
                                state = SKIP;
                        }
                        break;
                case D:
                        c = getch();
                        if (low(c) == 'u') {
                                state = DU;
                        } else {
                                printf("error: unknown command d%c\n", c);
                                state = SKIP;
                        }
                        break;
                case DU:
                        c = getch();
                        if (low(c) == 'p') {
                                return DUP;
                        } else {
                                printf("error: unknown command du%c\n", c);
                                state = SKIP;
                        }
                        break;
                case S:
                        c = getch();
                        if (low(c) == 'w') {
                                state = SW;
                        } else {
                                printf("error: unknown command s%c\n", c);
                                state = SKIP;
                        }
                        break;
                case SW:
                        c = getch();
                        if (low(c) == 'p') {
                                return SWP;
                        } else {
                                printf("error: unknown command sw%c\n", c);
                                state = SKIP;
                        }
                        break;
                case C:
                        c = getch();
                        if (low(c) == 'l') {
                                state = CL;
                        } else {
                                printf("error: unknown command c%c\n", c);
                                state = SKIP;
                        }
                        break;
                case CL:
                        c = getch();
                        if (low(c) == 'r') {
                                return CLR;
                        } else {
                                printf("error: unknown command cl%c\n", c);
                                state = SKIP;
                        }
                        break;
                default:
                        break;
                }
        }

        /*
        while ((c = getch()) == ' ' || c == '\t') {
        }

        s[1] = '\0';
        if (!isdigit(c) && c != '.' && c != '-') {
                return c;       / not a number /
        }
        i = 0;
        if (c == '-' && !isdigit(s[++i] = c = getch())) {
                ungetch(c);
                return '-';
        }
        if (isdigit(c)) {       / collect integer part /
                while (isdigit(s[++i] = c = getch())) {
                }
        }
        if (c == '.') {         / collect fraction part /
                while (isdigit(s[++i] = c = getch())) {
                }
        }
        s[i] = '\0';
        if (c != EOF) {
                ungetch(c);
        }
        return NUMBER;
        */
}

char low(char c) {
        return ('a' <= c && c <= 'z') ? c : c | 32;
}
