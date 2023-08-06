#define MAXLINES        5000
#define MAXLEN          1000

typedef int (*CompF)(void *, void*);

char *alloc(int);
void afree(int n);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, char reverse);
unsigned long getline2(char *, unsigned long);
void qsort(void *lineptr[], int left, int right, CompF comp);
int numcmp(char *, char *);
