typedef struct LinkedNode {
        struct LinkedNode *prev;        /* previous entry in chain */
        struct LinkedNode *next;        /* next entry in chain */
        char *name;                     /* defined name */
        char *defn;                     /* replacement text */
} LinkedNode;

LinkedNode *lookup(char*);
LinkedNode *install(char*, char*);
void undef(char*);
