#include<stdio.h>

#define MAXLEN          1000
#define CHAR_SIZE       256
#define WORD1           0
#define WORD2           1
#define SKIP            2

int any(char s1[], char s2[]);

/* Exercise 2-5. Write the function any( s1, s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 *  strpbrk does the same job but returns a pointer to the location.)
 */
int main(void) {
        char c;
        char word1[MAXLEN+1], word2[MAXLEN+1];
        int i, state;

        state = WORD1;
        i = 0;
        word1[0] = word2[0] = '\0';
        printf("To test the any function please input two words and press enter\n");
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
                                printf("There are no characters on the second word\n");
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
                                if (any(word1, word2) > -1) {
                                        printf("The first location of a character of "
                                                "'%s' on '%s' is at index: %d\n",
                                                word2, word1, any(word1, word2));
                                } else {
                                        printf("No character of '%s' match any of '%s'\n",
                                                word2, word1);
                                }
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

/* any: returns the first location of the string s1 where any character from
 * the string s2 occurs
 */
int any(char s1[], char s2[])
{
        int i;
        int appears[CHAR_SIZE];

        for (i = 0; i < CHAR_SIZE; i++) {
                appears[i] = 0;
        }
        for (i = 0; s2[i] != '\0'; i++) {
                appears[(unsigned)s2[i]] = 1;
        }
        for (i = 0; s1[i] != '\0'; i++) {
                if (appears[(unsigned)s1[i]]) {
                        return i;
                }
        }
        return -1;
}
