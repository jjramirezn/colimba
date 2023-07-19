#include <ctype.h>
#include <stdio.h>
#include "calc.h"

enum states {
        START,
        SKIP,
        NEGATIVE,
        INTEGER,
        DOT,
        FRACTIONAL,
        C,
        CL,
        CO,
        D,
        DU,
        E,
        EX,
        L,
        LO,
        P,
        PO,
        S,
        SI,
        SW,
        T,
        TO
};

static char low(char);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
        static int ch = -1;
        int i, c, state;
        state = START;

        i = 0;
        if (ch < 0) {
                c = getchar();
        } else {
                c = ch;
                ch = -1;
        }
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
                        } else if (low(c) == 'c') {
                                state = C;
                        } else if (low(c) == 'd') {
                                state = D;
                        } else if (low(c) == 'e') {
                                state = E;
                        } else if (low(c) == 'l') {
                                state = L;
                        } else if (low(c) == 'p') {
                                state = P;
                        } else if (low(c) == 't') {
                                state = T;
                        } else if (low(c) == 's') {
                                state = S;
                        } else {
                                return c;
                        }
                        break;
                case SKIP:
                        while ((c = getchar()) == ' ' || c == '\t') {
                        }
                        state = START;
                        break;
                case NEGATIVE:
                        c = getchar();
                        if (isdigit(c)) {
                                s[i++] = c;
                                state = INTEGER;
                        } else if (c == '.') {
                                s[i++] = '0';
                                s[i++] = '.';
                                state = DOT;
                        } else {
                                if (c != EOF) {
                                        ch = c;
                                }
                                return '-';
                        }
                        break;
                case INTEGER:
                        while (isdigit(s[i++] = c = getchar())) {
                        }
                        if (c == '.') {
                                state = DOT;
                        } else {
                                s[--i] = '\0';
                                if (c != EOF) {
                                        ch = c;
                                }
                                return NUMBER;
                        }
                        break;
                case DOT:
                        c = getchar();
                        if (isdigit(c)) {
                                state = FRACTIONAL;
                        } else {
                                s[--i] = '\0';
                                if (c != EOF) {
                                        ch = c;
                                }
                                return NUMBER;
                        }
                        break;
                case FRACTIONAL:
                        while (isdigit(s[i++] = c = getchar())) {
                        }
                        s[--i] = '\0';
                        if (c != EOF) {
                                ch = c;
                        }
                        return NUMBER;
                        break;
                case C:
                        c = getchar();
                        if (low(c) == 'l') {
                                state = CL;
                        } else if (low(c) == 'o') {
                                state = CO;
                        } else {
                                printf("error: unknown command c%c\n", c);
                                state = SKIP;
                        }
                        break;
                case CL:
                        c = getchar();
                        if (low(c) == 'r') {
                                return CLR;
                        } else {
                                printf("error: unknown command cl%c\n", c);
                                state = SKIP;
                        }
                        break;
                case CO:
                        c = getchar();
                        if (low(c) == 's') {
                                return COS;
                        } else {
                                printf("error: unknown command co%c\n", c);
                                state = SKIP;
                        }
                        break;
                case D:
                        c = getchar();
                        if (low(c) == 'u') {
                                state = DU;
                        } else {
                                printf("error: unknown command d%c\n", c);
                                state = SKIP;
                        }
                        break;
                case DU:
                        c = getchar();
                        if (low(c) == 'p') {
                                return DUP;
                        } else {
                                printf("error: unknown command du%c\n", c);
                                state = SKIP;
                        }
                        break;
                case E:
                        c = getchar();
                        if (low(c) == 'x') {
                                state = EX;
                        } else {
                                printf("error: unknown command e%c\n", c);
                                state = SKIP;
                        }
                        break;
                case EX:
                        c = getchar();
                        if (low(c) == 'p') {
                                return EXP;
                        } else {
                                printf("error: unknown command ex%c\n", c);
                                state = SKIP;
                        }
                        break;
                case L:
                        c = getchar();
                        if (low(c) == 'o') {
                                state = LO;
                        } else {
                                printf("error: unknown command l%c\n", c);
                                state = SKIP;
                        }
                        break;
                case LO:
                        c = getchar();
                        if (low(c) == 'g') {
                                return LOG;
                        } else {
                                printf("error: unknown command lo%c\n", c);
                                state = SKIP;
                        }
                        break;
                case P:
                        c = getchar();
                        if (low(c) == 'o') {
                                state = PO;
                        } else {
                                printf("error: unknown command p%c\n", c);
                                state = SKIP;
                        }
                        break;
                case PO:
                        c = getchar();
                        if (low(c) == 'w') {
                                return POW;
                        } else {
                                printf("error: unknown command po%c\n", c);
                                state = SKIP;
                        }
                        break;
                case S:
                        c = getchar();
                        if (low(c) == 'w') {
                                state = SW;
                        } else if (low(c) == 'i') {
                                state = SI;
                        } else {
                                printf("error: unknown command s%c\n", c);
                                state = SKIP;
                        }
                        break;
                case SI:
                        c = getchar();
                        if (low(c) == 'n') {
                                return SIN;
                        } else {
                                printf("error: unknown command si%c\n", c);
                                state = SKIP;
                        }
                        break;
                case SW:
                        c = getchar();
                        if (low(c) == 'p') {
                                return SWP;
                        } else {
                                printf("error: unknown command sw%c\n", c);
                                state = SKIP;
                        }
                        break;
                case T:
                        c = getchar();
                        if (low(c) == 'o') {
                                state = TO;
                        } else {
                                printf("error: unknown command t%c\n", c);
                                state = SKIP;
                        }
                        break;
                case TO:
                        c = getchar();
                        if (low(c) == 'p') {
                                return TOP;
                        } else {
                                printf("error: unknown command to%c\n", c);
                                state = SKIP;
                        }
                        break;
                default:
                        printf("fatal: illegal state\n");
                        return EOF;
                        break;
                }
        }
}

static char low(char c) {
        return ('a' <= c && c <= 'z') ? c : c | 32;
}
