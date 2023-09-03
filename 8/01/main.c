#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
        clock_t start, end, sum;
        FILE *fp;
        int fd, n;
        size_t r;
        char c,lowlevel = 0, *prog = argv[0], buff[BUFSIZ];

        if (argc < 2) {
                fprintf(stderr, "Usage: cat [-u] file [...]\n");
                fprintf(stderr, "-u : low level UNIX access.\n");
                exit(2);
        }

        while (--argc > 0 && (*++argv)[0] == '-') {
                while ((c = *++argv[0])) {
                        switch (c) {
                        case 'u':
                                lowlevel = 1;
                                break;
                        default:
                                printf("find: illegal option %c\n", c);
                                argc = 0;
                                break;
                        }
                }
        }
        ++argc;
        --argv;
        if (lowlevel) {
                start = clock();
                while (0 < --argc) {
                        if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                                fprintf(stderr, "%s: can't open %s\n",
                                        prog, *argv);
                                exit(1);
                        } else {
                                while ((n = read(fd, buff, BUFSIZ)) > 0) {
                                        if (write(1, buff, n) != n) {
                                                fprintf(stderr,
                                                        "cp: write error");
                                        }
                                }
                                close(fd);
                        }
                }
                end = clock();
        } else {
                start = clock();
                while (0 < --argc) {
                        if ((fp = fopen(*++argv, "r")) == NULL) {
                                fprintf(stderr, "%s: can't open %s\n",
                                        prog, *argv);
                                exit(1);
                        } else {
                                while ((r = fread(buff, sizeof(char), BUFSIZ, fp)) > 0) {
                                        if (fwrite(buff, sizeof(char), r, stdout) != r) {
                                                fprintf(stderr,
                                                        "cp: write error");
                                        }
                                }
                                fclose(fp);
                        }
                }
                end = clock();
        }
        sum = end - start;
        printf("Used %.3f ticks or %.3e seconds",
                (double) sum,
                (double) sum/ CLOCKS_PER_SEC);
        return 0;
}
