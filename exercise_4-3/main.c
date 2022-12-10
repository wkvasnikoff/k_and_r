/**
 * Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative
 * numbers.
 */

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>
#include <stdbool.h>

#define MAXOP 100 // max  size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char []);
void push(double);
double pop(void);
void ungetch(int c);
int getch();

// reverse Polish calculator
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push(((int)pop()) % (int)op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// ****************** Stack *******************

#define MAXVAL 100 // max stack size

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

// push: push f onto value stack
void push(double f)
{
    printf("push: %f\n", f);


    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


// getop: get next character or numberic operand
int getop(char s[])
{
    int i, c;
    bool is_number = false;

    // skip white space
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    // not a number
    i = 0;

    // handle negative numbers
    if (c == '-') {
        c = getch();
        if (isdigit(c) || c == '.') {
            is_number = true;
            s[0] = '-';
            i++;
        } else {
            ungetch(c);
            c = '-';
        }
    }

    // handle operators
    if (!is_number && c != '.') {
        s[1] = '\0';
        if (!isdigit(c) && c != '.' && c != '-') {
            return c;
        }
    }

    if (isdigit(c)) {
        // collect integer part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') {
        // collect fraction part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
// buffer for ungetch
// next free position in buf
int getch() /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
