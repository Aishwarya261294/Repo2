#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define MAX 50

using namespace std;

struct stack {
    int a[MAX];
    int top;
    };

struct stack s;

void push(int);
int eval(char, int, int);
int pop();

int main() {
    char c;

    int i,j,k, op1, op2;
    i = 0;
     char p[MAX];
     s.top = -1;

    while ((c = getchar()) != '\n') {

       j = 0;

       if (!isdigit(c) && c != ' ') {
            op1 = pop();
            op2 = pop();
            push(eval(c, op1, op2));
            } else if (c != ' ') {
                while (c != ' ' && isdigit(c)) {
                    p[j++] = c;
                    c = getchar();
                }
                p[j] = '\0';
                k = atoi(p);

                while (j-- >= 0) {
                    p[j] = '\0';
                }
                push(k);
            }
    }

    cout << pop() << "\n";

    return 0;
}

int eval (char c, int op1, int op2) {
    int n;
    switch(c) {
        case '+': n = op2 + op1;
            break;
        case '-': n = op2 - op1;
            break;
        case '*': n = op2 * op1;
            break;
        case '/': n = op2 / op1;
            break;
        case '^': n = pow(op2, op1);
            break;
            }
        return n;
}

void push(int c) {
    if (s.top != MAX - 1) {
        s.a[++s.top] = c;
    }
}

int pop() {
    if (s.top != -1) {
        return s.a[s.top--];
    }
}
