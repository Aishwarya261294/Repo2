#include <stdio.h>
#define MAX 100

struct stack {
    int st1[MAX];
    int st2[MAX];
    int top1, top2;
    int count;
}s;

void push1(int x)
{
    s.st1[++(s.top1)] = x;
}

int pop()
{
    return(s.st1[(s.top1)--]);
}

void push2(int x)
{
    s.st2[++(s.top2)] = x;
}

void insert()
{
    int x;

    printf("Enter data into stack\n");
    scanf("%d", &x);

    push1(x);
    s.count++;
}

void reverse()
{
    int i;

    for (i = 0; i < s.count; i++) {
            push2(pop());
    }
}

void display1()
{
    int i;
    if(s.top1 == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = s.top1; i >= 0; i--) {
            printf("%d ", s.st1[i]);
        }
    }
}

void display2()
{
    int i;
    if(s.top2 == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = s.top2; i >= 0; i--) {
            printf("%d ", s.st2[i]);
        }
    }
}
void main()
{
    int ch;
    s.count = 0;
    s.top1 = -1;
    s.top2 = -1;

    printf("1 - Push element into stack\n");
    printf("2 - Pop element from stack\n");
    printf("3 - Display1\n");
    printf("4 - Reverse the stack\n");
    printf("5 - Display2\n");
    printf("6 - Exit\n");

    while (1) {
        printf("Enter choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            pop();
            break;

        case 3:
            display1();
            break;

        case 4:
            reverse();
            break;

        case 5:
            display2();

        case 6:
            return;

        default:
            printf("Wrong choice\n");
        }
    }
}
