#include <stdio.h>
#include "getword.h"

#define MAXWORD         100

int main(void) {
        int wc;
        char word[MAXWORD];

        for (wc = 0; getword(word, MAXWORD) != EOF; ++wc) {
                printf("Found word: '%s'.\n", word);
        }
        printf("Found %d words.\n", wc);
        return 0;
}
