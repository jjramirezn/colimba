#include <limits.h>
#include <stdio.h>

main()
{
        int overflow = INT_MAX + 1;
        printf("%d", overflow);
}
