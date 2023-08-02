#include <math.h>
#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include "calc.h"

#define MAXOP   100     /* max size of operand or operator */

static int has_fractional(double);

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
        int type;
        double op1, op2;
        char s[MAXOP + 1];
        char **pargs = argv;
        if (argc < 2) {
                printf("Usage: expr {Reverse Polish Expression}\n");
                printf("We recommend escaping '*' and any other symbol that yourshell may interpret\n");
                printf("Example: expr 2 3 4 + \\*\n");
                return 1;
        }
        while(++pargs - argv < argc) {
                type = getop(*pargs, s);
                switch (type) {
                case NUMBER:
                        push(atof(s));
                        break;
                case SUM:
                        push(pop() + pop());
                        break;
                case MUL:
                        push(pop() * pop());
                        break;
                case MINUS:
                        op2 = pop();
                        push(pop() - op2);
                        break;
                case DIV:
                        op2 = pop();
                        if (op2 != 0.0) {
                                push(pop() / op2);
                        } else {
                                printf("error: zero divisor\n");
                        }
                        break;
                case MOD:
                        op2 = pop();
                        if (op2 != 0.0) {
                                op1 = pop();
                                if (has_fractional(op1) || has_fractional(op2)) {
                                        printf("warning: losing decimals due to modulo\n");
                                }
                                push((int) op1 % (int) op2);
                        } else {
                                printf("error: zero divisor\n");
                        }
                        break;
                case TOP:
                        printf("\t%.8g\n", top());
                        break;
                case DUP:
                        push(top());
                        break;
                case SWP:
                        op2 = pop();
                        op1 = pop();
                        push(op2);
                        push(op1);
                        break;
                case CLR:
                        clear();
                        break;
                case SIN:
                        push(sin(pop()));
                        break;
                case COS:
                        push(cos(pop()));
                        break;
                case EXP:
                        push(exp(pop()));
                        break;
                case LOG:
                        push(log(pop()));
                        break;
                case POW:
                        op2 = pop();
                        op1 = pop();
                        if (op1 == 0 && op2 <= 0) {
                                printf("error: zero divisor\n");
                        } else if (op1 < 0) {
                                if (has_fractional(op2)) {
                                        printf("warning: cannot handle imaginary numbers\n");
                                        printf("warning: losing decimals on exponent\n");
                                }
                                push(pow(op1, (int) op2));
                        } else {
                                push(pow(op1, op2));
                        }
                        break;
                default:
                        printf("error: unknown command %c\n", type);
                        break;
                }
        }
        printf("\t%.8g\n", top());
        return 0;
}

/* has_fractional: return 1 if the double cannot be converted safely to int */
static int has_fractional(double d)
{
        return d - (int) d != 0.0;
}
