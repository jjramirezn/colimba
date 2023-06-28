#include <stdio.h>

/* print Celsius-Farenheit table
 * for cels = -40, -30, ..., 100; floating-point version */
main()
{
        float fahr, celsius;
        int lower, upper, step;

        lower = -40;    /* lower limit of temperature table */
        upper = 100;    /* upper limit */
        step = 10;      /* step size */

        celsius = lower;
        printf("|------------------|\n");
        printf("|Celsius|Farenheit|\n");
        printf("|------------------|\n");
        while (celsius <= upper) {
                fahr = celsius*9.0/5.0 + 32.0;
                printf("|%7.0f|%10.1f|\n", celsius, fahr);
                celsius = celsius + step;
        }
        printf("|------------------|\n");
}
