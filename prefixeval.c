#include <stdio.h>
#include <math.h>
#include <string.h>

#define STACKSIZE 50

struct stack {
    int top;
    double arr[STACKSIZE];
};

struct stack s;

double oper(int a, double b, double c) {
    switch (a) {
        case '+' : return (b + c);
                    break;
        case '-' : return (b - c);
                    break;
        case '*' : return (b * c);
                    break;
        case '/' : return (b / c);
                    break;
        case '^' : return (pow(b,c));
                    break;
        default : printf("operation invalid");
                    return;
        }
}

void push(double x)
{
    if (s.top == STACKSIZE - 1) {
        printf("overflow");
    } else {
        s.arr[++s.top] = x;
    }
}

double pop()

{
    double x;

    if (isEmpty() == 0) {
        printf("underflow");
        return;
    } else {
        x = s.arr[s.top];
        s.top--;
        return x;
    }
}

int isEmpty()
{
    if (s.top == -1) {
        return 0;
    } else {
        return 1;
    }
}

double eval (char expr[])
{
    int c;
    int i;
    double op1;
    double op2;
    double value;
    int len;

    len = strlen (expr);

    for (i = len - 1; i > 0; i--) {
            c = expr[i];
        if (isdigit(c)) {
            push((double)(c - '0'));
        } else {
            op1 = pop();
            op2 = pop();
            value = oper(c, op2, op1);
            push (value);
        }
    }
    return pop();
}

void display()
{
    int i;

    if (isEmpty() == 0) {
        printf("no elements");
    } else {
        for (i = s.top; i >= 0; i--) {
            printf("%d", s.arr[i]);
        }
    }
}

int main()
{
    int i;
    char expr[STACKSIZE];

    i = 0;
    s.top = -1;

    while ((expr[i++] = getchar()) != '\n');

    expr[--i] = '\0';

    printf("The original prefix expression is %s\n", expr);

    printf("%f", eval(expr));

    return 0;
}
