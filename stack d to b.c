#include <stdio.h>
#define MAX 100

struct stack {
    int stk[MAX];
    int top;
}s;

void push(int x)
{
    if (s.top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s.top++;
        s.stk[s.top] = x;
    }
    return;
}

int pop()
{
    if (s.top == -1) {
        printf("Stack Underflow\n");
    }
    printf("%d", s.stk[s.top--]);
}

int main()
{
    int num = 0;
    int digit;

    printf("Enter the no. to convert into binary:\n");
    scanf("%d", &num);

    while (num > 0) {
        digit = num % 2;
        push (digit);
        num = num / 2;
    }
    while (s.top != 0) {
        pop ();
    }
    return 0;
}
