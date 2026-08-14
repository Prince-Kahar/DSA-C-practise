// postfix Second Name Polish Notation (PN).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char infix[MAX], temp[MAX], stack[MAX], postfix[MAX], temp2[MAX];
int top = -1;

void clearScreen();
void push(char ch);
char pop();

int main()
{
    int j = 0;
    clearScreen();
    printf("Enter Your Expression: ");
    fgets(infix, MAX, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        switch (ch)
        {

        case '(':
            push(ch);
            break;

        case ')':
            while (top != -1 && stack[top] != ')')
                postfix[j++] = pop();
            if (top != -1)
                pop();
            // push(ch);
            break;

        case '^':
            push(ch);
            break;

        case '*':
        case '/':
            while (top != -1 && stack[top] == '^')
                postfix[j++] = pop();
            push(ch);
            break;

        case '+':
        case '-':
            while (top != -1 && (stack[top] == '^' || stack[top] == '*' || stack[top] == '/' ))
                postfix[j++] = pop();
            push(ch);
            break;

        case ' ':
            continue;

        default:
            postfix[j++] = ch;
        }
    }

    while (stack[top] != -1)
    {
        if (stack[top] == '(' || stack[top] == ')')
            pop();
        else
            postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nInfix Expression: %s", infix);
    printf("\npostfix Expression: %s", postfix);
    return 0;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void push(char push_val)
{
    stack[++top] = push_val;
}

char pop()
{
    char pop_value = stack[top--];

    return pop_value;
}
