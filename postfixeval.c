#include <stdio.h>
#include <math.h>
#define STACKSIZE 50

struct stack {
    int top;
    double arr[STACKSIZE];
}s;

double oper(int a, double b, double c) {
    switch (a) {
        case '+' : return (c + b);
                    break;
        case '-' : return (c - b);
                    break;
        case '*' : return (c * b);
                    break;
        case '/' : return (c / b);
                    break;
        case '^' : return (pow(c,b));
                    break;
        default : printf("operation invalid\n");
                    return;
        }
}

void push(double x)
{
    if (s.top == STACKSIZE - 1) {
        printf("Overflow\n");
    } else {
        s.arr[++s.top] = x;
    }
}

double pop()
{
    double x;

    if (isEmpty() == 0) {
        printf("Underflow\n");
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

    for (i = 0; (c = expr[i]) != '\0'; i++) {
        if (isdigit(c)) {
            push((double)(c - '0'));
        } else {
            op1 = pop();
            op2 = pop();
            value = oper(c, op1, op2);
            push (value);
        }
    }
    return pop();
}

void display()
{
    int i;

    if (isEmpty() == 0) {
        printf("No elements\n");
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

    printf("The original postfix expression is %s\n", expr);

    printf("%f", eval(expr));

    return 0;
}
