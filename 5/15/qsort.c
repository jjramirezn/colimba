#include <string.h>
#include "qsort.h"


/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, CompF comp)
{
        int i, last;
        void swap(void *[], int, int);

        if (right <= left) {    /* do nothing if array contains */
                return;         /* fewer than two elements */
        }
        swap(v, left, (left + right)/2);
        last = left;
        for (i = left+1; i <= right; i++) {
                if (comp(v[i], v[left]) < 0) {
                        swap(v, ++last, i);
                }
        }
        swap(v, left, last);
        qsort(v, left, last-1, comp);
        qsort(v, last+1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
        char *temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}
