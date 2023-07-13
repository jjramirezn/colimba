#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */

double atof(char s[]);
unsigned long getline2(char line[], unsigned long maxline);

/* Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent.
 */
int main(void)
{
        char line[MAXLINE+1];

        while (getline2(line, MAXLINE) > 0) {
                printf("Value is %f\n", atof(line));
        }
        return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
        double val, power;
        int i, sign, esign, e;

        for (i = 0; isspace(s[i]); i++) {       /* skip white space */
                ;
        }
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
                i++;
        }
        for (val = 0.0; isdigit(s[i]); i++) {
                val = 10.0 * val + (s[i] - '0');
        }
        if (s[i] == '.') {
                i++;
        }
        for (power = 1.0; isdigit(s[i]); i++) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }
        val = sign * val / power;
        if (s[i] == 'E' || s[i] == 'e') {
                i++;
                esign = (s[i] == '-') ? -1 : 1;
                if (s[i] == '+' || s[i] == '-') {
                        i++;
                }
                for (e = 0; isdigit(s[i]); ++i) {
                        e = 10 * e + (s[i] - '0');
                }
                while (0 < e) {
                        val = esign < 0 ? val / 10 : val * 10;
                        --e;
                }
        }
        return val;
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
