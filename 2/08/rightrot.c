#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n);
unsigned getbits(unsigned x, int p, int n);

/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 */
int main(void)
{
        unsigned x, n;
        x = 0xac;       /*0b10101100*/
        n = 3;
        printf("x: 0x%x\n", x);
        printf("n: %d\n", n);
        printf("rightrot(x, n) = 0x%x\n", rightrot(x, n)); /* 0x95 */
        return 0;
}

/* rightrot: returns the value of x rotated n bits to the right */
unsigned rightrot(unsigned x, unsigned n)
{
        unsigned i;
        unsigned trail = getbits(x, n-1, n);
        x >>= n;
        for (i = 0; x >> i != 0; ++i) {
                ;
        }
        return x + (trail << i);
}

/* getbits: get n bits to the right from position p */
unsigned getbits(unsigned x, int p, int n)
{
        return (x >> (p+1-n)) & ~(~0 << n);
}
