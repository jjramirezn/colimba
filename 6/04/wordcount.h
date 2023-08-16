typedef struct IntList {
        int cap;
        int size;
        int *arr;
} IntList;

typedef struct WordNode {
        char *word;
        int count;
        IntList *lines;
        struct WordNode *left;
        struct WordNode *right;
} WordNode;

IntList *create_intlist(int);
void add(IntList*, int);
int getch(void);
void ungetch(int);
int getword(char*, int);
