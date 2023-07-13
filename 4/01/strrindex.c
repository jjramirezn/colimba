#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */

unsigned long getline2(char line[], unsigned long maxline);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";        /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
        char line[MAXLINE+1];
        int i;

        while (getline2(line, MAXLINE) > 0) {
                i = strrindex(line, pattern);
                if (i < 0) {
                        printf("Pattern \"%s\" not found.\n", pattern);
                } else {
                        printf("Pattern \"%s\" found at index %d.\n",
                                pattern, i);
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

/* strrindex: return rightmost occurence of t in s, -1 if none */
int strrindex(char s[], char t[])
{
        int i, j, k, ri;

        ri = -1;
        for (i = 0; s[i] != '\0'; i++) {
                for(j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++) {
                        ;
                }
                if (k > 0 && t[k] == '\0') {
                        ri = i;
                }
        }
        return ri;
}
