#include <stdio.h>

#define SWAP(T, X, Y) {T swap_temp = (X); (X) = (Y); (Y) = swap_temp;}

/* Exercise 4-14. Define a macro swap (t, x, y) that interchanges two
 * arguments of type t. (Block structure will help.)
 */
int main(void)
{
        int x = 3;
        int y = 5;
        printf("x=%d, y=%d\n", x, y);
        SWAP(int, x, y);
        printf("x=%d, y=%d\n", x, y);
        return 0;
}
