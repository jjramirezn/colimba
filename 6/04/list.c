#include <stdlib.h>
#include "wordcount.h"

IntList *create_intlist(int cap)
{
        IntList *lp = malloc(sizeof(IntList));
        int *ap = malloc(cap * sizeof(int));
        lp->cap = cap;
        lp->size = 0;
        lp->arr = ap;
        return lp;
}

void add(IntList *l, int x)
{
        if (l->cap <= l->size) {
                int i;
                int *ap = malloc(2 * l->cap * sizeof(int));
                for (i = 0; i < l->size; ++i) {
                        ap[i] = l->arr[i];
                }
                free(l->arr);
                l->cap *= 2;
                l->arr = ap;
        }
        l->arr[l->size++] = x;
}
