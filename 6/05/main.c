#include <stdio.h>
#include "table.h"

void print_if_present(char*);

int main(void) {
        install("first_name", "Juan");
        install("last_name", "Ramirez");
        install("age", "29");
        print_if_present("first_name");
        print_if_present("first_name");
        print_if_present("last_name");
        print_if_present("address");
        print_if_present("age");
        print_if_present("phone_number");
        printf("Undefing first_name\n");
        undef("first_name");
        undef("nothing");
        print_if_present("first_name");
        return 0;
}

void print_if_present(char *s) {
        LinkedNode *p = lookup(s);
        if (NULL == p) {
                printf("There is no value for '%s' in the table.\n", s);
        } else {
                printf("'%s': '%s'\n", s, p->defn);
        }
}
