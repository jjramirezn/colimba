#include <stdio.h>

#define ALLOCSIZE       10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
        if (n <= allocbuf + ALLOCSIZE - allocp) {
                allocp += n;
                return allocp - n;
        } else {
                return NULL;
        }
}

void afree(char *p)
{
        if (allocbuf <= p && p < allocbuf + ALLOCSIZE) {
                allocp = p;
        }
}
