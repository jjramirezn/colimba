#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

int main(void)
{
        unsigned x, p, n;
        x = 0xac;       /*0b10101100*/
        p = 2;
        n = 4;
        printf("x: 0x%x\n", x);
        printf("p: %d\n", p);
        printf("n: %d\n", n);
        printf("invert(x, p, n) = 0x%x\n", invert(x, p, n)); /* 0x90 */
        return 0;
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
        return x ^ ((~(~0 << n)) << p);
}
