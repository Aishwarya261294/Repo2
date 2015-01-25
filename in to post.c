#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100

struct stack
{
    int data[MAX];
    int top;
}s;

int priority(char);
void init();
int empty();
int full();
char pop();
void push(char);
char top();

void main()
{
    char x;
    int token;

    init();

    printf("Enter infix expression:\n");
    while((token = getchar())!='\0'){
        if(isalnum(token))
            printf("%c",token);
        else
            if(token == '(')
                push('(');
            else {
                if(token == ')')
                while((x = pop())!='(')
                printf("%c",x);
            else {
                while(priority(token) <= priority(top()) && !empty()) {
                    x = pop();
                    printf("%c",x);
                }
                push(token);
            }
        }
    }
    while(!empty()){
        x = pop();
        printf("%c",x);
    }
}

int priority(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
   return(3);
}

void init()
{
   s.top = -1;
}

int empty()
{
    if(s.top == -1)
        return(1);
    else
        return(0);
}

int full()
{
    if(s.top == MAX-1)
        return(1);
    else
        return(0);
}

void push(char x)
{
  s.top++;
  s.data[s.top]=x;
}

char pop()
{
   int x;
   x = s.data[s.top];
   s.top--;
   return(x);
}

char top()
{
   return(s.data[s.top]);
}
