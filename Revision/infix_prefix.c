#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

char infix[MAX], temp[MAX], stack[MAX], prefix[MAX];
int top = -1;

void strReverse(char str[MAX]);
void push(char);
char pop();

int main()
{
    int j = 0;
    char ch2;
    system("cls");

    printf("Enter Your Infix Expression: ");
    scanf("%[^\n]s", infix);

    // strcpy(temp, infix);

    strReverse(infix);
    printf("Revese Expression is : %s\n\n", temp);

    for (int i = 0; temp[i] != '\0'; i++)
    {
        char ch = temp[i];

        switch (ch)
        {
        case ')':
            push(ch);
            break;

        case '(':
            while (stack[top] != ')')
                prefix[j++] = pop();
            top--;
            break;

        case '^':
            push(ch);
            break;

        case '*':
        case '/':
            while (stack[top] == '^')
                prefix[j++] = pop();
            push(ch);
            break;

        case '+':
        case '-':
            while (stack[top] == '^' || stack[top] == '*' || stack[top] == '/')
                prefix[j++] = pop();
            push(ch);
            break;

        case ' ':
            continue;

        default:
            prefix[j++] = ch;
        }
    }

    for (int k = top; k > -1; k--)
    {
        ch2 = pop();
        if (ch2 != ')' || ch2 != '(')
            prefix[j++] = ch2;
    }

    strReverse(prefix);

    printf("Infix is: %s\n", infix);
    printf("Prefix is: %s\n", temp);
}

void strReverse(char str[MAX])
{
    int len = strlen(str);
    int j = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        temp[j] = str[i];
        j++;
    }
    temp[j] = '\0';
}

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}
