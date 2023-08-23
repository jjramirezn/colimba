#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
        char c, *pname;
        int i, (*transform)(int);
        int islash = -1;
        (void)argc; /* unused */

        for (i = 0; (c = argv[0][i]) != '\0'; ++i) {
                if ('/' == c) {
                        islash = i;
                }
        }
        pname = argv[0] + islash + 1;
        if (strcmp("lower", pname) == 0) {
                transform = tolower;
        } else if (strcmp("upper", pname) == 0) {
                transform = toupper;
        } else {
                printf("'%s' is not a valid name for this program\n", pname);
                printf("valid names: 'lower', 'upper'\n");
                return 1;
        }
        while ((c = getchar()) != EOF) {
                putchar(transform(c));
        }
        return 0;
}
