#define MAXLINES        5000
#define MAXLEN          1000

int readlines(char *lineptr[], int nlines);
int readlinesarr(char *lineptr[], int nlines, char *buff, int buffsize);
void writelines(char *lineptr[], int nlines);
void qsort(char * lineptr[], int left, int nlines);
unsigned long getline2(char *, unsigned long);
char *alloc(int);
