#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "minscan.h"

#define ISCONV(C)       ( 'i' == (C) || 'd' == (C) || 'o' == (C) || 'x' == (C) )

enum State {
        START,
        PERCENT,
        DEC,
        INT,
        OCT,
        HEX,
        CHAR,
        FLOAT
};

enum Modifier {
        NONE,
        SHRT,
        LNG
};

enum Base {
        ANY = 0,
        OCTAL = 8,
        DECIMAL = 10,
        HEXA = 16
};

/* minscanf: minimal scanf with varuable argument list */
int minscanf(char *fmt, ...)
{
        va_list ap;     /* points to each unnamed arg un turn */
        char *p;
        unsigned long ul;
        long l;
        unsigned char sign = 1, state = START, modifier = NONE, base = ANY;
        int c, nconv = 0;
        CharList *cbuff = create_charlist(10);
        p = fmt;

        startbuff();
        va_start(ap, fmt);      /* make ap point to 1st unnamed arg */
        while (*p) {
                switch (state) {
                case START:
                        if ('%' == *p) {
                                state = PERCENT;
                        } else {
                                c = getch();
                                if (EOF == c || c != *p) {
                                        goto end;
                                }
                        }
                        ++p;
                        break;
                case PERCENT:
                        switch (*p) {
                        case 'h':
                                modifier = SHRT;
                                ++p;
                                if (!ISCONV(*p) || 'u' != *p) {
                                        --p;
                                        base = ANY;
                                        state = INT;
                                }
                                break;
                        case 'l':
                                modifier = LNG;
                                ++p;
                                if (!ISCONV(*p) || 'u' != *p) {
                                        --p;
                                        base = ANY;
                                        state = INT;
                                }
                                break;
                        case 'd':
                                base = DECIMAL;
                                state = INT;
                                break;
                        case 'i':
                                base = ANY;
                                state = INT;
                                break;
                        case 'o':
                                base = OCTAL;
                                state = INT;
                                break;
                        case 'x':
                                base = HEXA;
                                state = INT;
                                break;
                        case 'u':
                                sign = 0;
                                ++p;
                                if (!ISCONV(*p)) {
                                        --p;
                                        base = ANY;
                                        state = INT;
                                }
                                break;
                        case 'c':
                                state = CHAR;
                                break;
                        case 'f':
                        case 'g':
                                state = FLOAT;
                                break;
                        case '%':
                                c = getch();
                                if (EOF == c || c != *p) {
                                        goto end;
                                }
                                ++p;
                                break;
                        default:
                                state = START;
                        }
                        break;
                case INT:
                        c = getch();
                        if ('+' == c || '-' == c) {
                                add(cbuff, c);
                                c = getch();
                        }
                        while(isdigit(c)) {
                                add(cbuff, c);
                                c = getch();
                        }
                        if (0 == cbuff->size) {
                                goto end;
                        }
                        add(cbuff, '\0');
                        if (sign) {
                                l = strtol(cbuff->arr, NULL, base);
                                switch (modifier) {
                                case NONE:
                                        *va_arg(ap, int *) = (int) l;
                                        break;
                                case SHRT:
                                        *va_arg(ap, long *) = l;
                                        break;
                                case LNG:
                                        *va_arg(ap, short *) = (short) l;
                                        break;
                                default:
                                        printf("error: illegal modifier\n");
                                        goto end;
                                        break;
                                }
                        } else {
                                ul = strtoul(cbuff->arr, NULL, base);
                                switch (modifier) {
                                case NONE:
                                        *va_arg(ap, unsigned *) = (unsigned) ul;
                                        break;
                                case SHRT:
                                        *va_arg(ap, unsigned long *) = ul;
                                        break;
                                case LNG:
                                        *va_arg(ap, unsigned short *) = (unsigned short) ul;
                                        break;
                                default:
                                        printf("error: illegal modifier\n");
                                        goto end;
                                        break;
                                }
                        }
                        ++nconv;
                        if (EOF == c) {
                                goto end;
                        }
                        ungetch(c);
                        state = START;
                        modifier = NONE;
                        sign = 0;
                        clean(cbuff);
                        ++p;
                        break;
                case CHAR:
                        c = getch();
                        if (EOF == c) {
                                goto end;
                        }
                        *va_arg(ap, char *) = c;
                        ++nconv;
                        state = START;
                        ++p;
                        break;
                case FLOAT:
                        c = getch();
                        if ('+' == c || '-' == c) {
                                add(cbuff, c);
                                c = getch();
                        }
                        while(isdigit(c)) {
                                add(cbuff, c);
                                c = getch();
                        }
                        if ('.' == c) {
                                add(cbuff, c);
                                c = getch();
                        }
                        while(isdigit(c)) {
                                add(cbuff, c);
                                c = getch();
                        }
                        if (0 == cbuff->size) {
                                goto end;
                        }
                        add(cbuff, '\0');
                        *va_arg(ap, double *) = strtod(cbuff->arr, NULL);
                        ++nconv;
                        if (EOF == c) {
                                goto end;
                        }
                        ungetch(c);
                        state = START;
                        clean(cbuff);
                        ++p;
                        break;
                default:
                        break;
                }
        }
        end:                    /* clean up when done */
        free_cl(cbuff);
        va_end(ap);
        return EOF == c ? c : nconv;
}
