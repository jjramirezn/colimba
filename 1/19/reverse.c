#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

unsigned long getline2(char line[], unsigned long maxline);
void reverse(char line[]);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
        unsigned long len;      /* current line length */
        char line[MAXLINE];     /* current input line */

        while ((len= getline2(line, MAXLINE)) > 0) {
                reverse(line);
                printf("%s", line);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
        to[i] = '\0';
}


/* reverse: reverses a str */
void reverse(char s[])
{
        int i, j;
        char tmp[MAXLINE];

        i = j = 0;
        copy(tmp, s);

        while(s[i] != '\0')
                ++i;
        --i;
        if (tmp[i] == '\n')
                --i;
        while (i >= 0) {
                s[j] = tmp[i];
                --i;
                ++j;
        }
        s[j] = '\n';
        s[j+1] = '\0';
}
