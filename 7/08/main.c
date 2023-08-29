#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
        FILE *fp;
        unsigned long pagen = 0;
        char c, *prog = argv[0];

        if (argc < 2) {
                fprintf(stderr, "Usage: page file [...]\n");
                exit(2);
        }
        while (0 < --argc) {
                if ((fp = fopen(*++argv, "r")) == NULL) {
                        fprintf(stderr, "%s: can't open %s\n",
                                prog, *argv);
                        exit(1);
                } else {
                        ++pagen;
                        printf("-------------------------------------------\n");
                        printf("Page: %ld\n", pagen);
                        printf("File: %s\n", *argv);
                        printf("-------------------------------------------\n");
                        while ((c = getc(fp)) != EOF) {
                                putchar(c);
                        }
                        printf("-------------------------------------------\n");
                        fclose(fp);
                }
        }
        return 0;
}
