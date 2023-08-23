#include <ctype.h>
#include <stdio.h>

#define BUFF_CAP     16

void printbuff(char *cbuff, unsigned len, unsigned cap);

int main(void)
{
        char c, cbuff[BUFF_CAP];
        unsigned i = 0;
        while ((c = getchar()) != EOF) {
                cbuff[i++] = c;
                if (BUFF_CAP <= i) {
                        printbuff(cbuff, i, BUFF_CAP);
                        i = 0;
                }
        }
        printbuff(cbuff, i + 1, BUFF_CAP);
        return 0;
}

void printbuff(char *cbuff, unsigned len, unsigned cap)
{
        unsigned i;
        for (i = 0; i < len; ++i) {
                printf("%02x ", cbuff[i]);
        }
        printf("%*s", 3 * (cap - len) + 2, "");
        for (i = 0; i < len; ++i) {
                putchar(isprint(cbuff[i]) ? cbuff[i] : '.');
        }
        putchar('\n');
}
