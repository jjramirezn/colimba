#include <stdio.h>

main()
{
        int notEOF = getchar() != EOF;
        printf("The value of getchar() != EOF is: %d.\n", notEOF);
        printf("This means that the character is ");
        if (notEOF)
                printf("not ");
        printf("the end of file.\n");
}
