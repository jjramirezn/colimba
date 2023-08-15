#include <ctype.h>
#include <stdio.h>
#include "getword.h"

enum {
        START,
        SKIP_B,
        SKIP_LINE,
        SKIP_STR,
        COMM_START,
        SKIP_COMMENT,
        COMM_END,
        WORD_START,
        WORD,
        END
};

/* getword: get next word or character from input */
int getword(char *word, int lim) {
        int c;
        char *w = word;
        char state = START;
        while ((c = getch()) != EOF) {
                if (START == state) {
                        if (isspace(c)) {
                                state = SKIP_B;
                        } else if ('#' == c) {
                                state = SKIP_LINE;
                        } else if ('\"' == c) {
                                state = SKIP_STR;
                        } else if ('/' == c) {
                                state = COMM_START;
                        } else {
                                ungetch(c);
                                state = WORD_START;
                        }
                } else if (SKIP_B == state) {
                        if (!isspace(c)) {
                                ungetch(c);
                                state = START;
                        }
                } else if (SKIP_STR == state) {
                        if ('\"' == c) {
                                state = START;
                        }
                } else if (SKIP_LINE == state) {
                        if ('\n' == c) {
                                state = START;
                        }
                } else if (COMM_START == state) {
                        if ('*' == c) {
                                state = SKIP_COMMENT;
                        } else {
                                state = START;
                        }
                } else if (SKIP_COMMENT == state) {
                        if ('*' == c) {
                                state = COMM_END;
                        }
                } else if (COMM_END == state) {
                        if ('/' == c) {
                                state = START;
                        } else {
                                state = SKIP_COMMENT;
                        }
                } else if (WORD_START == state) {
                        if (isalpha(c) || '_' == c) {
                                *w++ = c;
                                state = WORD;
                        } else {
                                state = START;
                        }
                } else if (WORD == state) {
                        if (lim <= 0) {
                                break;
                        } else if (isalnum(c) || '_' == c) {
                                *w++ = c;
                                --lim;
                        } else {
                                ungetch(c);
                                break;
                        }
                } else {
                        printf("getword: illegal state %d", state);
                        return EOF;
                }
        }
        *w = '\0';
        return c;
}
