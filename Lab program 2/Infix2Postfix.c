#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int top = -1;
char infix[50], stack[50], temp, x;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}

int pred(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^')
        return 3;
    return -1;
}

int main()
{
    int length;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");

    length = strlen(infix);

    for(int i = 0; i < length; i++)
    {
        temp = infix[i];

        if(isalnum(temp))
        {
            printf("%c", temp);
        }
        else if(temp == '(')
        {
            push(temp);
        }
        else if(temp == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while(top != -1 && pred(stack[top]) >= pred(temp))
            {
                printf("%c", pop());
            }
            push(temp);
        }
    }

    while(top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}
