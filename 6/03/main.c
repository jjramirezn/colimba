#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "wordcount.h"

#define MAXWORD         1000
#define MINWORD         3

WordNode *addtree(WordNode*, char*, int);
void treeprint(WordNode*);

int main(void)
{
        int len, c;
        WordNode *root = NULL;
        char word[MAXWORD];
        int nline = 1;
        while ((c = getch()) == '\n') {
                ++nline;
        }
        ungetch(c);
        while ((len = getword(word, MAXWORD)) != 0) {
                if (len > MINWORD && isalpha(word[0])) {
                        root = addtree(root, word, nline);
                }
                if ((c = getch()) == '\n') {
                        ++nline;
                } else {
                        ungetch(c);
                }
        }
        treeprint(root);
        return 0;
}

WordNode *addtree(WordNode *p, char *w, int nline)
{
        int cond;
        if (NULL == p) {
                p = malloc(sizeof(WordNode));
                p->word = strdup(w);
                p->count = 1;
                p->lines = create_intlist(10);
                add(p->lines, nline);
                p->left = p->right = NULL;
        } else if ((cond = strcmp(w, p->word)) == 0) {
                p->count++;
                add(p->lines, nline);
        } else if (cond < 0) {
                p->left = addtree(p->left, w, nline);
        } else {
                p->right = addtree(p->right, w, nline);
        }
        return p;
}

void treeprint(WordNode *p) {
        if (p != NULL) {
                int i;
                treeprint(p->left);
                printf("%s: { ", p->word);
                for (i = 0; i + 1 < p->lines->size; ++i) {
                        printf("%d, ", p->lines->arr[i]);
                }
                printf("%d }\n", p->lines->arr[i]);
                treeprint(p->right);
        }
}
