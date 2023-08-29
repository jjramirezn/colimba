#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char *argv[]) {
        FILE *f1p, *f2p;
        int comp;
        char *line1, *line2;
        size_t len1, len2;
        ssize_t r1, r2;
        unsigned nl = 0;
        char *prog = argv[0];   /* program name for errors */
        line1 = line2 = NULL;
        len1 = len2 = 0;
        if (3 != argc) {
                fprintf(stderr, "%s: need exactly two files, got %d\n",
                        prog, argc - 1);
                exit(2);
        }
        if ((f1p = fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
                exit(1);
        }
        if ((f2p = fopen(argv[2], "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, argv[2]);
                fclose(f1p);
                exit(1);
        }
        do {
                ++nl;
                r1 = getline(&line1, &len1, f1p);
                r2 = getline(&line2, &len2, f2p);
        } while ((comp = strcmp(line1, line2)) == 0 && -1 != r1 && -1 != r2);
        if (ferror(f1p)) {
                fprintf(stderr, "%s: error reading %s", prog, argv[1]);
                free(line1);
                free(line2);
                fclose(f1p);
                fclose(f2p);
                exit(1);
        }
        if (ferror(f2p)) {
                fprintf(stderr, "%s: error reading %s", prog, argv[2]);
                free(line1);
                free(line2);
                fclose(f1p);
                fclose(f2p);
                exit(1);
        }
        if (0 != comp) {
                printf("Files differ on line %d\n", nl);
                printf("%s: \"%s\"\n", argv[1], line1);
                printf("%s: \"%s\"\n", argv[2], line2);
        } else {
                printf("Files are identical.\n");
        }
        free(line1);
        free(line2);
        fclose(f1p);
        fclose(f2p);
        return 0;
}
