#include <stdio.h>
#define MAXSIZE 6

struct stack {
    int stk[MAXSIZE];
    int top1;
    int top2;
}s;

void push();
int  pop();
void display();

int main ()
{
    int choice;
    int option = 1;
    s.top1 = -1;
    s.top2 = MAXSIZE;

    printf ("STACK OPERATION\n");
    while (option) {
        printf ("------------------------------------------\n");
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
    return 0;
}

void push ()
{
    int num;
    int choice;

    if (s.top1 == s.top2 - 1) {
       printf("Stack is full\n");

    } else {
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        printf("enter 1 for stack1 or 2 for stack2\n");
        scanf("%d", &choice);

        if (choice == 1) {
            s.stk[++s.top1] = num;
        } else {
            s.stk[--s.top2] = num;
        }
    }
    return;
}

int pop ()
{
    int num;
    int choice;

    printf("Enter 1 for stack1 or 2 for stack2\n");
    scanf("%d", &choice);

    if (choice == 1) {
        if (s.top1 >= 0) {
            num = s.stk[s.top1];
            s.top1--;
        } else {
            printf("Stack1 is empty\n");
            return(s.stk[s.top1]);
        }
     } else {
        if (s.top2 < MAXSIZE) {
            num = s.stk[s.top2];
            s.top2++;
        } else {
            printf("Stack2 is empty\n");
            return(s.stk[s.top2]);
        }
    }
    return(num);
}

void display ()
{
    int i;
    if (s.top1 == -1) {
        printf ("Stack1 is empty\n");
        return;
    } else {
        printf ("The status of stack1 is \n");
        for (i = s.top1; i >= 0; i--) {
            printf("%d\n", s.stk[i]);
        }
    }

    if (s.top2 == MAXSIZE) {
        printf("stack 2 is empty\n");
        return;
    } else {
        printf("The status of stack2 is \n");
        for (i = MAXSIZE - 1; i >= s.top2; i--) {
            printf("%d\n",s.stk[i]);
        }
    }
}
