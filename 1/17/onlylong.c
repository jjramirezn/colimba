#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */
#define MINLINE 80    /* maximum input line size */

unsigned long getline2(char line[], unsigned long maxline);

/* print longest input line */
int main()
{
        unsigned long len;      /* current line length */
        char line[MAXLINE];     /* current input line */

        while ((len= getline2(line, MAXLINE)) > 0)
                if (len > MINLINE) {
                        printf("%s", line);
                        if (len > MAXLINE)
                                putchar('\n');
                }
        return 0;
}

/* getline2: read a line into s, return length; if the length is greater than
 *      the limit truncate the line but still report the correct length*/
unsigned long getline2(char s[], unsigned long lim)
{
        int c;
        unsigned long i;

        for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
                s[i] = '\0';
        } else if (c != EOF) {
                s[i] = '\0';
                while ((c=getchar()) != EOF && c !='\n')
                        ++i;
        }
        return i;
}
