#include <stdlib.h>
#include "minscan.h"

CharList *create_charlist(int cap)
{
        CharList *lp = malloc(sizeof(CharList));
        char *ap = malloc((cap + 1) * sizeof(char));
        lp->cap = cap;
        lp->size = 0;
        lp->arr = ap;
        return lp;
}

void add(CharList *l, char x)
{
        if (l->cap <= l->size) {
                int i;
                char *ap = malloc(2 * l->cap * sizeof(char));
                for (i = 0; i < l->size; ++i) {
                        ap[i] = l->arr[i];
                }
                free(l->arr);
                l->cap *= 2;
                l->arr = ap;
        }
        l->arr[l->size++] = x;
}

void clean(CharList *l) {
        l->size = 0;
        *l->arr = '\0';
}

void free_cl(CharList *l) {
        free(l->arr);
        free(l);
}
