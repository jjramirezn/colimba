#include <stdio.h>
#include <string.h>

#define MAX_STR 11

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
        char s[MAX_STR+1];
        itoa(-2147483648, s);
        printf("%s\n", s);
        return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
        int i, sign;

        if ((sign = n) < 0) {           /* record sign */
                n = -n;                 /* make n positive */
        }
        i = 0;
        if (n < 0) {
                /* at this point n == INT_MIN so unsigned n would be its positive */
                s[i++] = ((unsigned) n) % 10 + '0';
                n /= -10;
        }
        do {                            /* generate digits in reverse order */
                s[i++] = n % 10 + '0';  /* get next digit */
        } while ((n /= 10) > 0);        /* delete it */
        if (sign < 0) {
                s[i++] = '-';
        }
        s[i] = '\0';
        reverse(s);
}

/* reverse: reverse string s in plave */
void reverse(char s[])
{
        int c, i, j;

        for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}
