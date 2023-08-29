#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
        FILE *fp;
        int c, except, number, found;
        unsigned long lineno = 0;
        char *pattern, *line = NULL;
        char *prog = argv[0];
        size_t len = 0;
        except = number = found = 0;

        while (--argc > 0 && (*++argv)[0] == '-') {
                while ((c = *++argv[0])) {
                        switch (c) {
                        case 'x':
                                except = 1;
                                break;
                        case 'n':
                                number = 1;
                                break;
                        default:
                                printf("find: illegal option %c\n", c);
                                argc = 0;
                                break;
                        }
                }
        }

        if (argc < 1) {
                printf("Usage: find -x -n pattern\n");
                exit(2);
        }
        if (1 == argc) {
                while (getline(&line, &len, stdin) > 0) {
                        ++lineno;
                        if ((strstr(line, *argv) != NULL) != except) {
                                if (number) {
                                        printf("%ld:", lineno);
                                }
                                printf("%s", line);
                                ++found;
                        }
                }
        } else {
                pattern = *argv;
                while (0 < --argc) {
                        if ((fp = fopen(*++argv, "r")) == NULL) {
                                fprintf(stderr, "%s: can't open %s\n",
                                        prog, *argv);
                                exit(1);
                        } else {
                                while (getline(&line, &len, fp) > 0) {
                                        ++lineno;
                                        if ((strstr(line, pattern) != NULL) != except) {
                                                if (number) {
                                                        printf("%s:%ld:", *argv, lineno);
                                                }
                                                printf("%s", line);
                                                ++found;
                                        }
                                }
                                lineno = 0;
                                fclose(fp);
                        }
                }
        }
        free(line);
        printf("Found the pattern %d times.\n", found);
        return 0;

}
