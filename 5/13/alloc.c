#include <stdio.h>
#include "tail.h"

#define ALLOCSIZE       10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
static char *freep = allocbuf;

char *alloc(int n)
{
        if (allocp < freep) {
                if (allocp + n <= freep) {
                        allocp += n;
                        return allocp - n;
                } else {
                        return NULL;
                }
        } else if (allocp - allocbuf + n <= ALLOCSIZE) {
                allocp += n;
                return allocp - n;
        } else if (n <= freep - allocbuf) {
                allocp = allocbuf + n;
                return allocbuf;
        } else {
                return NULL;
        }
}

void afree(int n)
{
        if (freep < allocp) {
                freep = freep + n < allocp ? freep + n : allocp;
        } else if (allocp < freep) {
                int pdiff = freep - allocbuf;
                if (pdiff + n < ALLOCSIZE) {
                        freep += n;
                } else {
                        freep = allocbuf;
                        n -= ALLOCSIZE - pdiff;
                        afree(ALLOCSIZE - pdiff + n);
                }
                freep = freep - allocbuf + n < ALLOCSIZE ? freep + n : allocbuf;
        }
}
