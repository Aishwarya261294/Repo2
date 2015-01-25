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

int pop1()
{
    return(s.st1[(s.top1)--]);
}

void push2(int x)
{
    s.st2[++(s.top2)] = x;
}

int pop2()
{
    return(s.st2[s.top2--]);
}

void enqueue()
{
    int x;

    printf("Enter data into queue");
    scanf("%d", &x);

    push1(x);
    s.count++;
}

void dequeue()
{
    int i;

    for (i = 0; i <= s.count; i++) {
            push2(pop1());
    }

    pop2();
    s.count--;

    for (i = 0; i <= s.count; i++) {
            push1(pop2());
    }
}

void display()
{
    int i;

    for (i = s.top1; i >= 0; i--) {
            printf(" %d ", s.st1[i]);
    }
}


void main()
{
    int ch;
    s.count = 0;
    s.top1 = -1;
    s.top2 = -1;

    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");


    while (1) {
        printf("\nEnter choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return;

        default:
            printf("Wrong choice");
        }
    }
}
