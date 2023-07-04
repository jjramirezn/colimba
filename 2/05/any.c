#include<stdio.h>

#define MAXLEN  1000

int any(char s1[], char s2[]);

/* Exercise 2-5. Write the function any( s1, s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 *  strpbrk does the same job but returns a pointer to the location.)
 */
int main(void) {
        char c;
        char word1[MAXLEN], word2[MAXLEN];
        int wordn, i;

        wordn = 1;
        i = 0;
        while((c = getchar()) != EOF) {
                if (c == ' ') {
                        if (wordn == 1) {
                                wordn = 2;
                                word1[i] = '\0';
                                i = 0;
                        }
                } else if (c == '\n') {
                        word2[i] = '\0';
                        wordn = 1;
                        i = any(word1, word2);
                        if (i > -1) {
                                printf("The first location of a character of "
                                        "'%s' on '%s' is at index: %d\n",
                                        word2, word1, any(word1, word2));
                        } else {
                                printf("No character of '%s' match any of '%s'\n",
                                        word2, word1);
                        }
                        i = 0;
                } else if (wordn == 1) {
                        word1[i++] = c;
                } else if (wordn == 2) {
                        word2[i++] = c;
                }
        }
        return 0;
}

/* any: returns the first location of the string s1 where any character from
 * the string s2 occurs
 */
int any(char s1[], char s2[])
{
        int i, j, min;

        min = -1;
        for (i = 0; s2[i] != '\0'; i++) {
                for (j = 0; s1[j] != '\0'; j++) {
                        if (s1[j] == s2[i]) {
                                if (min == -1 || j < min) {
                                        min = j;
                                }
                                break;
                        }
                }
                if (min == 0) {
                        break;
                }
        }

        return min;
}
