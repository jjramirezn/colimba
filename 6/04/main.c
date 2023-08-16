#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "wordcount.h"

#define MAXWORD         1000
#define MINWORD         3

WordNode *addtree(WordNode*, char*, int);
void treeprint(WordNode*);
void reorder(WordNode*, WordNode*);
WordNode *insert(WordNode*, WordNode*);

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
        reorder(NULL, root);
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

void treeprint(WordNode *p)
{
        if (p != NULL) {
                treeprint(p->right);
                printf("%d\t%s\n", p->count, p->word);
                treeprint(p->left);
        }
}

void reorder(WordNode *root, WordNode* node) {
        if (NULL != node) {
                WordNode *left = node->left;
                WordNode *right = node->right;
                node->left = NULL;
                node->right = NULL;
                if (NULL == root) {
                        root = node;
                } else {
                        insert(root, node);
                }
                reorder(root, left);
                reorder(root, right);
        }
}


WordNode *insert(WordNode *into, WordNode *node)
{
        if (NULL == into) {
                return node;
        } else if (node->count <= into->count) {
                into->left = insert(into->left, node);
        } else {
                into->right = insert(into->right, node);
        }
        return into;
}
