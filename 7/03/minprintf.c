#include <stdarg.h>
#include <stdio.h>

/* minprintf: minimal printf with varuable argument list */
void minprintf(char *fmt, ...)
{
        va_list ap;     /* points to each unnamed arg un turn */
        char *p, *sval;
        int ival;
        double dval;
        char conv[3] = "%%";

        va_start(ap, fmt);      /* make ap point to 1st unnamed arg */
        for (p = fmt; *p; p++) {
                if (*p != '%') {
                        putchar(*p);
                        continue;
                }
                switch (*++p) {
                case 'd':
                case 'i':
                case 'o':
                case 'x':
                case 'X':
                        conv[1] = *p;
                        ival = va_arg(ap, int);
                        printf(conv, ival);
                        break;
                case 'f':
                case 'e':
                case 'E':
                case 'g':
                case 'G':
                        conv[1] = *p;
                        dval = va_arg(ap, double);
                        printf(conv, dval);
                        break;
                case 's':
                        for (sval = va_arg(ap, char *); *sval; sval++) {
                                putchar(*sval);
                        }
                        break;
                default:
                        putchar(*p);
                        break;
                }
        }
        va_end(ap);     /* clean up when done */
}
