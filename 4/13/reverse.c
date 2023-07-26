#include <stdio.h>
#include <string.h>

#define MAXLINE 1000    /* maximum input line size */

void reverse(char s[], unsigned left, unsigned right);
void swap(char v[], unsigned i, unsigned j);
unsigned long getline2(char s[], unsigned long lim);

/* Exercise 4-13. Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */
int main(void) {
        unsigned long len;      /* current line length */
        char line[MAXLINE + 1];     /* current input line */

        while ((len= getline2(line, MAXLINE)) > 0) {
                reverse(line, 0, len - 1);
                printf("%s\n", line);
        }
        return 0;
}
/* reverse: reverse string s in place using recursion */
void reverse(char s[], unsigned left, unsigned right)
{
        if (right <= left) {
                return;
        }
        swap(s, left, right);
        reverse(s, ++left, --right);
}

void swap(char v[], unsigned i, unsigned j)
{
        char t;
        t = v[i];
        v[i] = v[j];
        v[j] = t;
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
