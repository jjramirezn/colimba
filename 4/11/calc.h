int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);
int getch(void);
void ungetch(int);

/* operator types, careful if we have more than 10, dont overwrite existing chars */
enum optypes {
        NUMBER,
        TOP,
        DUP,
        SWP,
        CLR,
        SIN,
        COS,
        EXP,
        LOG,
        POW,            /* 9 */
        NL = '\n',      /* 10 */
        MOD = '%',      /* 37 */
        MUL = '*',      /* 42 */
        SUM = '+',      /* 43 */
        MINUS = '-',    /* 45 */
        DIV = '/'       /* 47 */
};
