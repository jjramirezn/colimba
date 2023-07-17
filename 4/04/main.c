#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include "enums.h"

#define MAXOP   100     /* max size of operand or operator */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);
int has_fractional(double);

/* reverse Polish calculator */
int main(void)
{
        int type;
        double op1, op2;
        char s[MAXOP + 1];
        while ((type = getop(s)) != EOF) {
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
                case NL:
                        printf("\t%.8g\n", top());
                        break;
                default:
                        printf("error: unknown command %c\n", type);
                        break;
                }
        }
        return 0;
}

/* has_fractional: return 1 if the double cannot be converted safely to int */
int has_fractional(double d)
{
        return d - (int) d != 0.0;
}
