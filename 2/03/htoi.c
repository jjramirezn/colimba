#include <stdio.h>

#define AHEX    10
#define BASE    16
#define MAXLINE 1000

int htoi(char hex[]);
unsigned long getline2(char line[], unsigned long maxline);

/* Exercise 2-3. Write the function h t o i ( s ) , which converts a string of
 * hexa-decimal digits (including an optional Ox or Ox) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */
int main(void)
{
        char line[MAXLINE];
        int n;

        while (getline2(line, MAXLINE) > 0) {
                n = htoi(line);
                printf("hex: 0x%x|dec: %d|\n", n, n);
        }
        return 0;
}

/* htoi: convert s to integer; s is the hexadecimal representation of an int */
int htoi(char s[]){
        int i, n, d;
        n = 0;
        for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i) {
                if (i == 0 && s[i] == '0') {
                        ++i;
                } else {
                        if (s[i] >= '0' && s[i] <= '9') {
                                d = s[i] - '0';
                        } else if (s[i] >= 'a' && s[i] <= 'f') {
                                d = s[i] - 'a' + AHEX;
                        } else if (s[i] >= 'A' && s[i] <= 'F') {
                                d = s[i] - 'A' + AHEX;
                        }
                        n = BASE * n + d;
                }
        }
        return n;
}

/* getline2: read a line into s, return length; if the length is greater than
 *      the limit truncate the line but still report the correct length*/
unsigned long getline2(char s[], unsigned long lim)
{
        int c;
        unsigned long i;

        for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
                s[i] = c;
        }
        if (c == '\n') {
                s[i++] = c;
                s[i] = '\0';
        } else if (c == EOF) {
                s[i] = '\0';
        } else {
                s[i] = '\0';
                while ((c=getchar()) != EOF && c !='\n') {
                        ++i;
                }
        }
        return i;
}
