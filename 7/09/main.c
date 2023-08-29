#include <stdio.h>
#include <time.h>

#define isupper_smallslow(C)    ( 'A' <= (C) && (C) <= 'Z' )
#define isupper_bigfast(C)      ( upper_table[(C)] )
#define TRIES                   1000000

char upper_table[256] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int main(void)
{
        clock_t start, end, sum1, sum2;
        unsigned tries = TRIES;
        FILE *randchars;
        char c, isupper;
        sum1 = sum2 = 0;

        randchars = popen(
                "LC_ALL=C tr -dc 'A-Za-z0-9' </dev/urandom",
                "r");
        while(0 < --tries) {
                c = getc(randchars);
                start = clock();
                isupper = isupper_smallslow(c);
                end = clock();
                sum1 += end - start;
        }
        tries = TRIES;
        while(0 < --tries) {
                c = getc(randchars);
                start = clock();
                isupper = isupper_bigfast(c);
                end = clock();
                sum2 += end - start;
        }
        pclose(randchars);
        printf("smallslow used %.3f ticks or %.3e seconds in average\n",
                (double) sum1 / TRIES,
                (double) sum1 / TRIES / CLOCKS_PER_SEC);
        printf("bigfast used %.3f ticks or %.3e seconds in average\n",
                (double) sum2 / TRIES,
                (double) sum2 / TRIES / CLOCKS_PER_SEC);
        return 0;
}

