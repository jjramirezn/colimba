#define MAXLINES        5000
#define MAXLEN          1000

char *alloc(int);
void afree(int n);
int readlines(char *lineptr[], int nlines);
unsigned long getline2(char *, unsigned long);
