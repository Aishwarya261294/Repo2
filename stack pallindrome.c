#include <stdio.h>
#include <string.h>
#define MAX 100

struct stack {
    int stk[MAX];
    int top;
}s;

void push(char);
char pop();

int main()
{
    char str[MAX];
    int i, count = 0, len = 0;

    printf("Enter string to check it is palindrome or not : ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len; i++) {
            push(str[i]);
    }
    for (i = 0; i < len; i++) {
        if (str[i] == pop())
        count++;
    }
    if (count == len) {
        printf("%s is a Palindrome string\n", str);
    } else {
        printf("%s is not a Palindrome string\n", str);
    }
    return 0;
}
/* Function to push character into stack */

void push(char c)
{
    s.stk[++s.top] = c;
}
/* Function to pop the top character from stack */

char pop()
{
    return(s.stk[s.top--]);
}
