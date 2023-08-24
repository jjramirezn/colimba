#include <stdio.h>

void minprintf(char *fmt, ...);

int main(void)
{
        minprintf("Hola Carola\n");
        minprintf("%s\n", "Hola Carola");
        minprintf("%d\t%f\n", 0, 3.14);
        minprintf("%d\t%o\n", 1, 100);
        minprintf("%d\t%x\n", 2, 100);
        minprintf("%d\t%X\n", 3, 100);
        minprintf("%d\t%e\n", 4, 10.30491839);
        minprintf("%d\t%E\n", 4, 10.30491839);
        minprintf("%d\t%g\n", 4, 10.30491839);
        minprintf("%d\t%G\n", 4, 10.30491839);
        return 0;
}
