#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float fahrtocelsius(float fahr);

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
        float fahr;

        printf("|------------------|\n");
        printf("|Fahrenheit|Celsius|\n");
        printf("|------------------|\n");
        for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
                printf("|%10.0f|%7.1f|\n", fahr, fahrtocelsius(fahr));
        printf("|------------------|\n");
        return 0;
}

float fahrtocelsius(float fahr) {
         return (5.0/9.0) * (fahr-32.0);
}
