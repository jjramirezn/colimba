#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
        double v1, v2;

        v1 = atof(s1);
        v2 = atof(s2);
        if (v1 < v2) {
                return -1;
        } else {
                return v2 < v1 ? 1 : 0;
        }
}
