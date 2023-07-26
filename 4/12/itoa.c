#include <stdio.h>
#include <string.h>

#define MAX_STR 11

void itoa(int n, char **p);

/* Exercise4-12. Adapt theideasofprintd towritearecursiveversionof itoa; that
 * is, convert an integer into a string by calling a recursive routine.
 */
int main(void) {
        char s[MAX_STR+1] = "";
        char *ps = s;
        itoa(2147483647, &ps);
        printf("%s\n", s);
        return 0;
}

/* itoa: convert an int to a string using recursion */
void itoa(int n, char **p)
{
        if (n < 0) {
                **p = '-';
                (*p)++;
                n = -n;
        }
        if (n / 10) {
                itoa(n / 10, p);
        }
        **p = n % 10 + '0';
        (*p)++;
        **p = '\0';
}
