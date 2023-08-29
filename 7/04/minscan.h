typedef struct CharList {
        int cap;
        int size;
        char *arr;
} CharList;

int minscanf(char *, ...);
CharList *create_charlist(int);
void add(CharList*, char);
void clean(CharList*);
void free_cl(CharList*);
int getch(void);
void ungetch(int);
void startbuff(void);
