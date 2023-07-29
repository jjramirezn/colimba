#include <stdio.h>

#ifndef MAXSIZE
#define MAXSIZE 1000
#endif

char *strncpy2(char *s, char *ct, int n);
char *strncat2(char *s, char *ct, int n);
int strncmp2(char *cs, char *ct, int n);

/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their argument
 * strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */
int main(void)
{
        char s[MAXSIZE + 1] = "Formiga";
        printf("%s\n", strncpy2(s, "Hola Carola", 1));
        printf("%s\n", strncpy2(s, "Hello World", 100));
        printf("%s\n", strncpy2(s, "Hola Carola", 11));
        printf("%s\n", strncpy2(s, "Hello World", 12));
        printf("%s\n", strncpy2(s, "Hola Carola", 5));
        printf("%s\n", strncat2(s, "Como estan todos?", 9));
        printf("%s\n", strncat2(s, "No escribas esto", 0));
        printf("%d\n", strncmp2("Hola Carola", "Hola Mundo", 5));
        printf("%d\n", strncmp2("Hola Carola", "Hola Mundo", 4));
        printf("%d\n", strncmp2("Hola Carola", "Hola Mundo", 6));
        printf("%d\n", strncmp2("a", "b", 10000));
        return 0;
}

/* strncpy2: copy at most n characters of string ct to s; return s. Pad with
 * '\0 's if t has fewer than n characters.
 */
char *strncpy2(char *s, char *ct, int n)
{
        char *s0 = s;
        while (s - s0 < n) {
                if ('\0' == *ct) {
                        break;
                }
                *s++ = *ct++;
        }
        while (s - s0 < n) {
                *s++ = '\0';
        }
        return s0;
}

/* strncat2: concatenate at most n characters of string ct to string s,
 * terminate s with '\0'; return s.
 */
char *strncat2(char *s, char *ct, int n)
{
        char *s0 = s;
        char *ct0 = ct;
        if (n == 0) {
                return s;
        }
        while ('\0' != *s) {
                ++s;
        }
        while ((*s++ = *ct++) && ct - ct0 < n) {
        }
        *s = '\0';
        return s0;
}

/* strncmp2: compare at most n characters of string cs to string ct; return <0
 * if cs<ct, 0 if cs==ct, or >0 if cs>ct.
 */
int strncmp2(char *s, char *ct, int n)
{
        char *s0 = s;
        for ( ;*s == *ct && *s != '\0' && s - s0 < n - 1; ++s, ++ct) {
        }
        return *s - *ct;
}
