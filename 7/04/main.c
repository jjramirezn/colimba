#include <stdio.h>
#include "minscan.h"

int main(void)
{
        double d1, d2;
        unsigned u;
        printf("Input a sum of two floats:\n");
        minscanf("%f+%f", &d1, &d2);
        printf("The sum of %f and %f is %f\n", d1, d2, d1 + d2);
        printf("Input a positive exponent to get a power of two:\n");
        minscanf("%u", &u);
        printf("2 to the power of %u is %d\n", u, 1 << u);
        return 0;
}
