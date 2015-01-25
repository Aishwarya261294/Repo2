#include <stdio.h>
#define MAX 100

struct stack {
    int stk1[MAX];
    int stk2[MAX];
    int top1;
    int top2;
}s;

void push1(int x)
{
    if (s.top1 == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s.top1++;
        s.stk1[s.top1] = x;
    }
    return;
}

void push2(int y)
{
    if (s.top2 == MAX - 1) {

    } else {

    }
    return;
}

int pop1()
{
    if (s.top1 == -1) {
        printf("Stack Underflow\n");
    }
    return(s.stk1[s.top1--]);
}

int getmin()
{
    if (s.top2 == -1) {
        printf("Stack Underflow\n");
    }
    return(s.stk2[s.top2--]);
}

int main()
{
    int x;
    int y;
    s.top1 = s.top2 = -1;

    y = s.top2;

    if (x < y) {
        push2(x);
    } else {
        push1(x);
    }
    return 0;
}
