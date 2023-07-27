#include <stdio.h>

#ifndef DEFSTRCAT
#define DEFSTRCAT
#define MAXSIZE 1000
#endif


void strcat2(char *s, char*t);

/* Exercise 5-3. Write a pointer version of the function strcat that we showed
 * in Chapter 2: strcat(s,t) copies the string t to the end of s.
 */
int main(void)
{
        char s[MAXSIZE + 1] = "Hola ";
        strcat2(s, "Carola");
        printf("%s\n", s);
        return 0;
}

/* strcat2: concatenate t to the end of s; s must be big enough */
void strcat2(char *s, char*t)
{
        while ('\0' != *s) {
                ++s;
        }
        while ((*s++ = *t++)) {
        }
}
