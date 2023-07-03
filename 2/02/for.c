#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

long getline2(char line[], unsigned long maxline);

/* Exercise 2-2. Write a loop equivalent to the for loop above without using
 * && or !!.
 * for (i=0; i<lim-1 && (c=getchar()) != '\n ' && c != EOF; ++i) s[i] = c;
 */
int main(void)
{
        long len;      /* current line length */
        char line[MAXLINE];     /* current input line */

        while ((len= getline2(line, MAXLINE)) > 0) {
                printf("%s", line);
        }

        return 0;
}

long getline2(char s[], unsigned long lim)
{
        int c;
        unsigned long i;

        c = getchar();
        for(i = 0; (i < (lim-1)) + (c != EOF) + (c != '\n') == 3; ++i) {
                s[i] = c;
                c = getchar();
        }
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
