#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

unsigned long getline2(char line[], unsigned long maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
        unsigned long len;      /* current line length */
        unsigned long max;      /* maximum length seen so far */
        char line[MAXLINE];     /* current input line */
        char longest[MAXLINE];  /* longest line saved here */

        max = 0;
        while ((len= getline2(line, MAXLINE)) > 0)
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        if (max > 0) {    /* there was a line */
                printf("The longest line was %ld chars long.\n", max);
                if (max > MAXLINE)
                        printf("The line was truncated to %d chars and is printed bellow\n%s\n",
                                        MAXLINE, longest);
                else {
                        printf("Printed bellow is the line.\n%s", longest);
                }
        }
        return 0;
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
        } else {
                s[i] = '\0';
                while ((c=getchar()) != EOF && c !='\n') {
                        ++i;
                }
        }
        return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}

