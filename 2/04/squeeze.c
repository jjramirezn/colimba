#include<stdio.h>

#define MAXLEN          1000
#define CHAR_SIZE       256
#define WORD1           0
#define WORD2           1
#define SKIP            2

void squeeze(char s1[], char s2[]);

/* Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2.
 */
int main(void) {
        char c;
        char word1[MAXLEN+1], word2[MAXLEN+1];
        int i, state;

        state = WORD1;
        i = 0;
        word1[0] = word2[0] = '\0';
        printf("To test the squeeze function please input two words and press enter\n");
        while((c = getchar()) != EOF) {
                if (WORD1 == state) {
                        if (MAXLEN == i) {
                                printf("Please try again with %d or fewer chars per word\n",
                                        MAXLEN);
                                word1[i] = '\0';
                                i = 0;
                                state = SKIP;
                        } else if (' ' == c || '\t' == c) {
                                state = WORD2;
                                word1[i] = '\0';
                                i = 0;
                        } else if ('\n' == c) {
                                squeeze(word1, word2);
                                printf("%s\n", word1);
                                word1[0] = '\0';
                                i = 0;
                        } else {
                                word1[i++] = c;
                        }
                } else if (WORD2 == state) {
                        if (MAXLEN == i) {
                                printf("Please try again with %d or fewer chars per word\n",
                                        MAXLEN);
                                word1[0] = word2[0] = '\0';
                                i = 0;
                                state = SKIP;
                        } else if (' ' == c || '\t' == c || '\n' == c) {
                                word2[i] = '\0';
                                squeeze(word1, word2);
                                printf("%s\n", word1);
                                word1[0] = word2[0] = '\0';
                                i = 0;
                                state = WORD1;
                        } else {
                                word2[i++] = c;
                        }
                } else if (SKIP == state) {
                        if ('\n' == c) {
                                state = WORD1;
                        }
                }
        }
        return 0;
}

/* squeeze: deletes each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
        unsigned int i, j;
        int appears[CHAR_SIZE];

        for (i = 0; i < CHAR_SIZE; ++i) {
                appears[i] = 0;
        }
        for (i = 0; s2[i] != '\0'; i++) {
                appears[(unsigned)s2[i]] = 1;
        }
        for (i = j = 0; s1[i] != '\0'; i++) {
                if (!appears[(unsigned)s1[i]]) {
                        s1[j++] = s1[i];
                }
        }
        s1[j] = '\0';
}
