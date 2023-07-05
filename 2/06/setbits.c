#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */
int main(void)
{
        unsigned x, y, p, n;
        x = 0xac;       /*0b10101100*/
        y = 0xeb;       /*0b11101011*/
        p = 5;
        n = 3;
        printf("x: 0x%x\n", x);
        printf("y: 0x%x\n", y);
        printf("p: %d\n", p);
        printf("n: %d\n", n);
        printf("setbits(x, p, n, y) = 0x%x\n", setbits(x, p, n, y)); /* 0x6c */
        return 0;
}

/*setbits: sets the n bits of x that start on position p with the rightmost n
 * bits of y */
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
        return (x & ~((~(~0 << n)) << p)) + (getbits(y, n-1, n) << p);
}

/* getbits: get n bits to the right from position p */
unsigned getbits(unsigned x, int p, int n)
{
        return (x >> (p+1-n)) & ~(~0 << n);
}
