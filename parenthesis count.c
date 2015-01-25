#include<stdio.h>
#include<string.h>
#define MAX 30

struct stack {
    int stk[MAX];
    int top;
}s;

void push(char);
char pop();
int match(char, char);
//int pcount(char);


int check(char exp[])
{
    int i;
    char temp;

    for(i = 0; i < strlen(exp); i++) {

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);

        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(s.top == -1) {
               // printf("Right parentheses are more than left parentheses\n");
                return 0;
            } else {
                temp = pop();

                if(!match(temp, exp[i])) {
                   // printf("Mismatched parentheses are : ");
                    return 0;
                 //   printf("%c and %c\n", temp, exp[i]);
                }
            }
        }
    }

    if(s.top == -1) {
       // printf("valid expression\n");
        return 1;
    } else {
       // printf("left parenthesis is more than right one\n");
        return 0;
    }

    return 0;
}

int match(char a, char b)
{
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '(' && b == ')')
        return 1;

    return 0;
}

void push(char item)
{
    if(s.top == (MAX - 1)) {
        printf("Stack Overflow\n");
        return;
    }
    s.top++;
    s.stk[s.top] = item;
}

char pop()
{
    if(s.top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    return(s.stk[s.top--]);
}

int pcount(char exp[])
{
    int i;
    int count = 0;

    for(i = 0; i < strlen(exp); i++) {

        if(exp[i] == '('  || exp[i] == '['  || exp[i] == '{')
            count++;
     }
    printf("%d", count);
    printf("\n");
    return 0;
}

int main()
{
    char exp1[MAX];
    char exp2[MAX];
    int valid;

    s.top = -1;

    //printf("Enter an algebraic expression : \n");
    gets(exp1);
    gets(exp2);

    valid = check(exp1);

    if(valid == 1) {
        printf("GOOD EXPRESSION\n");
        pcount(exp1);
   } else {
        printf("NO\n");
   }


    valid = check(exp2);

    if(valid == 1) {
        printf("GOOD EXPRESSION\n");
        pcount(exp2);

    } else {
        printf("NO\n");
    }
    return 0;
}
