#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX 100

using namespace std;
struct stack  {
    int top;
    int item[MAX];
};
int isempty(struct stack *st);
int full(struct stack *st);
void push(struct stack *st, int x);
int pop(struct stack *st);
void merge(struct stack *st1, struct stack *st2);
void display(struct stack *st);

int  main()
{
    struct stack st1,st2;
    int  i;
    char x;


    st1.top = st2.top = -1;

    for(i = 0; i >= 0; i++){
        x  = getchar();
        if(isdigit(x)) {
            push(&st1,x - '0');
        } else if (x  == '\n') {
            break;
        }
    }

    for(i = 0; i >= 0; i++){
        x  = getchar();
        if(isdigit(x)) {
            push(&st2,x - '0');
        } else if (x  == '\n') {
            break;
        }
    }
    merge(&st1, &st2);
    display(&st1);

    return 0;
}

 void display(struct stack *st1)
 {

    int i;
    for(i = 0;i <= st1->top; i++) {
        cout << st1->item[i] <<" ";
    }
    cout << endl;
}
int isempty(struct stack *st)
{
    if (st->top == -1)
        return 0;
    else
        return 1;
}
int full(struct stack *st)
{
    if(st->top == MAX - 1)
        return 0 ;

    else
        return 1;
}
int pop(struct stack *st)
{
    if (!isempty(st)){
        cout<< "empty stack";
    }
    return (st->item[st->top--]);
}
void push(struct stack *st, int x)
{
    if (!(full(st))){
        cout << "stack is full";
    } else
        st->item[++(st->top)]=x;

    return;
}

void merge(struct stack *st1, struct stack *st2)
{

    int i;
    int j;
    int count;
    int x;
    int a[MAX];

    i = 0;
    count = 0;
    while(st1->top > 0) {
        a[i++] = pop(st1);
        count++;
    }

    j = count -1;

    for (i = 0; i >= 0; i++) {
        if (isempty(st2)) {
            x = pop(st2);
            push(st1, x);
        }

        if (j >= 0) {
            push(st1, a[j]);
            j--;
        }

        if ( j < 0 && !isempty(st2)) {
            break;
        }
    }
    return;
}
