#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

/* Exercise 5-4. Write the function strend(s,t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise.
 */
int main(void)
{
        char *s = "Hola Carola";
        char *t = "Hola, como estas Carola";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "Hola Carola";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "Carola";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "World";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "Carol";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "Hola";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "a";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        t = "";
        printf("\"%s\" is %sat the end of \"%s\".\n",
                        t, strend(s, t) ?  "" : "not ", s);
        return 0;
}

/* strend: returns 1 if the t occurs at the end of s, zero otherwise */
int strend(char *s, char *t)
{
        size_t lens = strlen(s);
        size_t lent = strlen(t);
        if (lens < lent) {
                return 0;       /* t can't be contained in s if it's bigger */
        }
        s += lens - lent;
        for (; *s == *t; s++, t++) {
                if ('\0' == *s) {
                        return 1;
                }
        }
        return 0;
}
