#include <stdio.h>

#define STRING_LIMIT 1000

void escape(char to[], char from[]);
void parse(char to[], char from[]);

/* Exercise 3-2. Write a function escape (s, t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies
 * the string t to s. Use a switch. Write a function for the other direction
 * as well, converting escape sequences into the real characters.
 */
int main(void)
{
        char c;
        char s[2*STRING_LIMIT+1];
        char t[STRING_LIMIT+1];
        unsigned i;

        for (i = 0; (c = getchar()) != EOF && i < STRING_LIMIT; ++i) {
                t[i] = c;
        }
        t[i] = '\0';
        escape(s, t);
        printf("%s\n", s);
        for (i = 0; t[i] != '\0'; ++i) {        /* delete t */
                t[i] = '\0';
        }
        parse(t, s);
        printf("%s\n", t);
        return 0;
}

/* escape: converts newline and tab into visible escape sequences as it copies
 * from into to; assumes that to is big enough
 */
void escape(char to[], char from[])
{
        unsigned i, j;

        for (i = j = 0; from[i] != '\0'; ++i,++j) {
                switch (from[i]) {
                        case '\n':
                                to[j++] = '\\';
                                to[j] = 'n';
                                break;
                        case '\t':
                                to[j++] = '\\';
                                to[j] = 't';
                                break;
                        default:
                                to[j] = from[i];
                                break;
                }
        }
        to[j] = '\0';
}

/* parse: converts \n and \t escape sequences into characters as it copies
 * from into to; assumes that to is big enough
 */
void parse(char to[], char from[])
{
        unsigned i, j;

        for (i = j = 0; from[i] != '\0'; ++i,++j) {
                if ('\\' == from[i]) {
                        switch (from[++i]) {
                                case 'n':
                                        to[j] = '\n';
                                        break;
                                case 't':
                                        to[j] = '\t';
                                        break;
                                default:
                                        to[j++] = '\\';
                                        to[j] = from[i];
                                        break;
                        }
                } else {
                        to[j] = from[i];
                }
        }
        to[j] = '\0';
}
