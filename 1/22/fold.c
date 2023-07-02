#include <stdio.h>

#define LIMIT 80

#define BLANK 0
#define WORD  1

/* Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with
 * very long lines, and if there are no blanks or tabs before the specified
 * column.
 */
int main(void)
{
        int c, i, lastb, state;
        char line[LIMIT+1];

        i = lastb = 0;
        state = BLANK;
        line[LIMIT] = '\0';
        while ((c = getchar()) != EOF) {
                if (i == LIMIT) {
                        if (c == ' ' || c == '\t') {
                                printf("%s\n", line);
                                i = lastb = 0;
                        } else if (lastb > 0) {
                                line[lastb] = '\0';
                                printf("%s\n", line);
                                for (i = 0; i < LIMIT-lastb-1; ++i) {
                                        line[i] = line[i+lastb+1];
                                }
                                lastb = 0;
                        } else {
                                printf("%s-\n", line);
                                i = 0;
                        }
                }

                if (c == '\n') {
                        line[i] = '\0';
                        printf("%s\n", line);
                        i = lastb = 0;
                } else if (c == ' ' || c == '\t') {
                         if (i != 0 && state == WORD) {
                                line[i] = c;
                                lastb = i;
                                state = BLANK;
                                ++i;
                        }
                } else {
                        line[i] = c;
                        state = WORD;
                        ++i;
                }
        }
        if (i > 0) {
                line[i] = '\0';
                printf("%s", line);
        }
        return 0;
}
