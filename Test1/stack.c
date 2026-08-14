/*

Q1. Stack Using Array (20 Marks)
 1. Push 5 elements into the Stack.
 2. Pop 2 elements from the Stack.
 3. Display the updated Stack.
 4. Bonus: Find and display the largest element present in the Stack.
    Bonus:
    -> Perform Stack Operations using Linked List
    -> Decimal to Binary using Stack
    -> Palindrome using Stack
    -> String Reverse using Stack

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX], top = -1;

void menu();
void push();
void pop();
void display();
void largeElement();

int main()
{
    system("cls");
    menu();
    return 0;
}

void menu()
{
    int ch;
    do
    {
        printf(" ---------------- Stack Operations ---------------- \n");
        printf(" | 1. Push                                        | \n");
        printf(" | 2. Pop                                         | \n");
        printf(" | 3. Display                                     | \n");
        printf(" | 4. Largest Element                             | \n");
        printf(" | 5. Exit                                        | \n");
        printf(" -------------------------------------------------- \n");

        printf("Enter Your choice (1 - 5): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            system("cls");
            push();
            break;

        case 2:
            system("cls");
            pop();
            break;

        case 3:
            system("cls");
            display();
            break;

        case 4:
            system("cls");
            largeElement();
            break;

        case 5:
            system("cls");
            printf("Byyy");
            return;

        default:
            printf("You are Choose Wrong Operations\n");
        }

    } while (ch != 5);
}

void push()
{
    if (top == MAX - 1)
    {
        printf("Stack is Overflow\n");
        return;
    }

    int val;

    printf("Enter a Value for insert: ");
    scanf("%d", &val);

    top++;
    stack[top] = val;
    printf("%d is Inserted Succefully .... \n", val);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is UnderFlow \n");
        return;
    }

    printf("%d is Deleted Succeffully ... \n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is UnderFlow \n");
        return;
    }

    for (int i = 0; i <= top; i++)
        printf("%d\t", stack[i]);
    printf("\n");
}

void largeElement()
{
    if (top == -1)
    {
        printf("Stack is UnderFlow \n");
        return;
    }

    int max = stack[0];

    for (int i = 1; i <= top; i++)
        if(stack[i] < stack[i+1])
            max = stack[i];

    printf("largest Element is %d ... \n", max);
}
