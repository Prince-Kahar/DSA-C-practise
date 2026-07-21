#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

char infix[SIZE], stack[SIZE], postfix[SIZE];
int top = -1;

void push(char);
char pop();

int main()
{
    int j = 0;
    char temp[SIZE], ch;
    system("cls");

    printf("Enter Your Expression: ");
    scanf("%[^\n]s", infix);

    strcpy(temp, infix);

    // infix[strcspan(infix, '\n')] = '\0';

    for (int i = 0; temp[i] != '\0'; i++)
    {
        ch = temp[i];
        switch (ch)
        {
        case '(':
            push(ch);
            break;

        case ')':
            while (stack[top] != '(')
                postfix[j++] = pop();
            top--;
            break;

        case '^':
            push(ch);
            break;

        case '*':
        case '/':
            while (stack[top] == '^')
                postfix[j++] = pop();
            push(ch);
            break;

        case '+':
        case '-':
            while ((stack[top] == '^' || stack[top] == '*' || stack[top] == '/'))
                postfix[j++] = pop();
            push(ch);
            break;

        case ' ':
            continue;
            break;

        default:
            postfix[j++] = ch;
        }
    }

    while (top != -1)
    {
        ch = pop();
        if (ch != '(')
            postfix[j++] = ch;
    }
  

    printf("Infix Expression: %s\n", infix);
    printf("postfix Expression: %s\n", postfix);
}

void push(char push_val)
{
    stack[++top] = push_val;
}

char pop()
{
    return stack[top--];
}
