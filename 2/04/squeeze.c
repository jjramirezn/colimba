#include<stdio.h>

#define MAXLEN  1000

void squeeze(char s1[], char s2[]);

/* Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2.
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
                        i = 0;
                        squeeze(word1, word2);
                        printf("%s\n", word1);
                } else if (wordn == 1) {
                        word1[i++] = c;
                } else if (wordn == 2) {
                        word2[i++] = c;
                }
        }
        return 0;
}

/* squeeze: deletes each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
        char c;
        int i, j, k;

        for (i = 0; s2[i] != '\0'; i++) {
                c = s2[i];
                for (j = k = 0; s1[j] != '\0'; j++) {
                        if (s1[j] != c) {
                                s1[k++] = s1[j];
                        }
                }
                s1[k] = '\0';
        }
}
