#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define HASHSIZE        6947

static LinkedNode *hashtab[HASHSIZE];

/* hash: form hash value for string s */
static unsigned hash(char *s)
{
        unsigned hashval;
        for (hashval = 0; *s != '\0'; ++s) {
                hashval = *s + 31 * hashval;
        }
        return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
LinkedNode *lookup(char *s)
{
        LinkedNode *np;

        for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
                if (strcmp(s, np->name) == 0) {
                        return np;      /* found */
                }
        }
        return NULL;                    /* not found */
}

/* install: put (name, defn) in hashtab */
LinkedNode *install(char *name, char *defn)
{
        LinkedNode *np;
        unsigned hashval;

        if ((np = lookup(name)) == NULL) {      /* not found */
                np = malloc(sizeof(*np));
                if (np == NULL || (np->name = strdup(name)) == NULL) {
                        return NULL;
                }
                hashval = hash(name);
                np->next = hashtab[hashval];
                hashtab[hashval] = np;
                if (NULL != np->next) {
                        np->next->prev = np;
                }
        } else {        /*already there */
                free(np ->defn); /* free previous defn */
        }
        if ((np->defn = strdup(defn)) == NULL) {
                return NULL;
        }
        return np;
}

void undef(char *name)
{
        LinkedNode *p = lookup(name);
        if (NULL != p) {
                if (NULL == p->prev) {
                        hashtab[hash(name)] = p->next;
                } else {
                        p->prev->next = p->next;
                }
                if (NULL != p->next) {
                        p->next->prev = p->prev;
                }
                free(p->name);
                free(p->defn);
                free(p);
        }
}
