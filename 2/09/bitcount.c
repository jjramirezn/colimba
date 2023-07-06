#include <stdio.h>

int bitcount(unsigned x);

/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 * Response: substracting 1 in a two's complement system converts all zeroes to
 * ones up until the first 1 that it converts to zero (starting from the right)
 * leaving all other bytes the same. Then when you perform the & operation, all
 * the zeroes of x before the first 1 will do 0 & 1 and remain zero and the
 * first one to the right will perform 1 & 0 and flip to zero. All of the other
 * bits will perform 0 & 0 and 1 & 1 and remain the same. example:
 *      x =             0b10101100
 *      x - 1 =         0b10101011
 *      x & (x - 1) =   0b10101000
 */
int main(void)
{
        unsigned x = 0xac;
        printf("0x%x has %d bits set to 1\n", x, bitcount(x));  /* 4 */
        return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
        int b;
        for (b = 0; x != 0; x &= x - 1) {
                b++;
        }
        return b;
}
