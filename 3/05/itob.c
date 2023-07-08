#include <stdio.h>
#include <string.h>

#define MAX_STR 33

void itoa(int n, char s[], int b);
void reverse(char s[]);
char obtain_char(int d, int b);

/* Exercise 3-5. Write the function itob(n, s, b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s
 */
int main(void)
{
        int i;
        char s[MAX_STR + 1];
        for (i = -50; i < 51; ++i) {
                printf("%d is: ", i);
                itoa(i, s, 2);
                printf("%s in binary, ", s);
                itoa(i, s, 8);
                printf("%s in octal, ", s);
                itoa(i, s, 16);
                printf("%s in hexadecimal, ", s);
                itoa(i, s, 32);
                printf("%s in Base32, ", s);
                itoa(i, s, 64);
                printf("%s in Base64, ", s);
                itoa(i, s, 92);
                printf("%s in base 92.\n", s);

        }
        i = -2147483648;
        printf("%d is: ", i);
        itoa(i, s, 2);
        printf("%s in binary, ", s);
        itoa(i, s, 8);
        printf("%s in octal, ", s);
        itoa(i, s, 16);
        printf("%s in hexadecimal, ", s);
        itoa(i, s, 32);
        printf("%s in Base32, ", s);
        itoa(i, s, 64);
        printf("%s in Base64, ", s);
        itoa(i, s, 92);
        printf("%s in base 92.\n", s);
        i = 2147483647;
        printf("%d is: ", i);
        itoa(i, s, 2);
        printf("%s in binary, ", s);
        itoa(i, s, 8);
        printf("%s in octal, ", s);
        itoa(i, s, 16);
        printf("%s in hexadecimal, ", s);
        itoa(i, s, 32);
        printf("%s in Base32, ", s);
        itoa(i, s, 64);
        printf("%s in Base64, ", s);
        itoa(i, s, 92);
        printf("%s in base 92.\n", s);
        i = 1994;
        printf("%d is: ", i);
        itoa(i, s, 2);
        printf("%s in binary, ", s);
        itoa(i, s, 8);
        printf("%s in octal, ", s);
        itoa(i, s, 16);
        printf("%s in hexadecimal, ", s);
        itoa(i, s, 32);
        printf("%s in Base32, ", s);
        itoa(i, s, 64);
        printf("%s in Base64, ", s);
        itoa(i, s, 92);
        printf("%s in base 92.\n", s);
        return 0;
}

/* itoa: convert n to characters in s in base b; 1 < b < 93 */
void itoa(int n, char s[], int b)
{
        int i, sign;

        if ((sign = n) < 0) {           /* record sign */
                n = -n;                 /* make n positive */
        }
        i = 0;
        if (n < 0) {
                s[i++] = obtain_char(-(n % b), b);
                n /= -b;
        }
        do {                                    /* generate digits in reverse order */
                s[i++] = obtain_char(n % b, b); /* get next digit */
        } while ((n /= b) > 0);                /* delete it */
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

/* obtain_char: obtains the corresponding char acording to base; d < b;
 * 1 < b < 93; b <= 10 will use digits as normal, b = 16 || b = 32 || b = 64
 * will use RFC 4648. Every other case will use the printable ascii chars
 * (ignoring '-') from 33 to 126 being '!' == 0 and '~' == 92
 */
char obtain_char(int d, int b) {
        char c;
        switch (b) {
                case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
                case 10:
                        c = d + '0';
                        break;
                case 16:
                        c = d < 10 ? d + '0' : d - 10 + 'a';
                        break;
                case 32:
                        c = d < 26 ? d + 'A' : d - 26 + '2';
                        break;
                case 64:
                        if (d < 26 ) {
                                c = d + 'A';
                        } else if (d < 52) {
                                c = d - 26 + 'a';
                        } else if (d < 62) {
                                c = d - 52 + '0';
                        } else {
                                c = 62 == d ? '+' : '/';
                        }
                        break;
                default:
                        c = d < '-' - '!' ? d + '!' : d + 1 + '!';
                        break;
        }
        return c;
}
