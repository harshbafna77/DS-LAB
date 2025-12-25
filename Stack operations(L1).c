#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE], top=-1;

void push(int value)
{
    if(top==SIZE-1)
    {
        printf("\nOverflow! Stack is full.\n");
    }
    else
    {
        top++;
        stack[top]=value;
        printf("\nInsertion  successful! %d added to the stack.\n",value);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nUnderflow!Stack is empty.");
    }
    else
    {
        printf("\nDeleted element is %d\n",stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty.");
    }
    else
    {
        printf("\nStack elements are:\n");
        for(i=top; i>=0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int value, choice;
    while(1)
    {
        printf("\n\n*******MENU*******");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                   printf("\nEnter a value:");
                   scanf("%d",&value);
                   push(value);
                   break;
                }
            case 2:
                {
                    pop();
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            case 4:
                {
                    exit(0);
                }
            default:
                {
                    printf("\nWrong input.");
                }


        }
    }
}



