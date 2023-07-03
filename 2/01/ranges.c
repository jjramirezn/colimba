#include <stdio.h>
#include <limits.h>
#include <float.h>

#define NEG -1


/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */
int main(void) {
        float f;
        printf("Using limits.h and float.h:\n");
        printf("|       |%37ssigned|%17sunsigned|\n", "", "");
        printf("|char   |%32s[%d, %d]|%17s[0, %d]|\n", "", SCHAR_MIN, SCHAR_MAX, "", UCHAR_MAX);
        printf("|short  |%28s[%d, %d]|%15s[0, %d]|\n", "", SHRT_MIN, SHRT_MAX, "", USHRT_MAX);
        printf("|int    |%18s[%d, %d]|%10s[0, %u]|\n", "", INT_MIN, INT_MAX, "", UINT_MAX);
        printf("|long   |[%ld, %ld]|[0, %lu]|\n", LONG_MIN, LONG_MAX, ULONG_MAX);
        printf("|float  |%15s[%e, %e]|%25s|\n", "", FLT_MIN, FLT_MAX, "");
        printf("|double |%13s[%e, %e]|%25s|\n", "", DBL_MIN, DBL_MAX, "");
        putchar('\n');
        printf("Manually calculating:\n");
        /* Ugly but much better than trying to count up to the max */
        printf("|       |%37ssigned|%17sunsigned|\n", "", "");
        printf("|char   |%32s[%d, %d]|%17s[0, %d]|\n", "",
                (signed char) ((unsigned char)NEG/2 + 1),
                (signed char) ((unsigned char)NEG/2), "",
                (unsigned char)NEG);
        printf("|short  |%28s[%hd, %hd]|%15s[0, %hu]|\n", "",
                (signed short) ((unsigned short)NEG/2 + 1),
                (signed short) ((unsigned short)NEG/2), "",
                (unsigned short)NEG);
        printf("|int    |%18s[%d, %d]|%10s[0, %u]|\n", "",
                (signed int) ((unsigned int)NEG/2 + 1),
                (signed int) ((unsigned int)NEG/2), "",
                (unsigned int)NEG);
        printf("|long   |[%ld, %ld]|[0, %lu]|\n",
                (signed long) ((unsigned long)NEG/2 + 1),
                (signed long) ((unsigned long)NEG/2),
                (unsigned long)NEG);
        for (f = 1.0; f < f * 2.0; f *= 2.0)
                ;
        printf("Maximum float calculated: %f\n", f);
        for (f = 1.0; f > f / 2.0; f /= 2.0)
                ;
        printf("Minimum float calculated: %f\n", f);
        printf("TODO: floats and doubles calculated\n");
        return 0;
}
