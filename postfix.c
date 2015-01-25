#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100

struct stack{
    int top;
    char a[maxsize];
}s;

void push(char x)
{
    //(s.top)++;
    s.a[++(s.top)] = x;

    return;
}

char pop()
{
    char x;
    x = s.a[s.top];
    (s.top)--;

    return x;
}

int isempty()
{
    if(s.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int priority(char b)
{
    switch(b) {
    case '-' :
    case '+' :
        return 1;
        break;
    case '*' :
    case '/' :
        return 2;
        break;
    case '^' :
        return 3;
        break;
    default :
        return 0;
        break;
    }
}

int main()
{
    int i;
    int j;
    int d;
    int v;
    char y[maxsize];
    char out[maxsize];
    char temp;
    char symb;

    scanf("%s", y);
    d = strlen(y);
    s.top = -1;

   /* for(i = 0; i < d; i++) {
        if(y[i] == '(') {
            y[i] = ')';
    } else if(y[i] == ')') {
            y[i] = '(';
    }
    }*/

    v = 0;

    for (i = 0; i < d; i++) {
            symb = y[i];
            if(symb == '(') {
                push(symb);
            } else if (symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '^') {
                while ((s.top != -1) && (priority(s.a[s.top]) >= priority(symb))) {
                    out[v] = pop();
                    v++;
                    }
            push(symb);
        }  else if (symb == ')') {
                while((temp = pop()) != '(') {
                        out[v] = temp;
                        v++;
                }
                //push(symb);
            } else {
                out[v] = symb;
                v++;
            }
    }

    while(isempty() != 1){
        out[v] = pop();
        v++;
    }

    out[v] = '\0';
    printf("the prefix string is %s\n", out);

    return 0;
}

