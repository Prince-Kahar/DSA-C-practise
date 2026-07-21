#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top = -1, simple_stack[SIZE];

void menu();
void Operation(int);

int full()
{
    if (top == SIZE - 1)
        return 1;
    return 0;
}

int empty()
{
    if (top == -1)
        return 1;
    return 0;
}

void push();
void pop();
void display();

int main()
{
    system("cls");
    menu();
}

void menu()
{
    int choice;
    system("cls");

    do
    {
        printf("---------------- Stack Operation ----------------\n");
        printf("| 1. Push                                        |\n");
        printf("| 2. Pop                                         |\n");
        printf("| 3. Display                                     |\n");
        printf("| 4. Exit                                        |\n");
        printf("--------------------------------------------------\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);

        Operation(choice);
    } while (choice != 4);
}

void Operation(int choice)
{
    switch (choice)
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
        printf("Byy Kal milna\n");
        break;

    default:
        system("cls");
        printf("Are You made \n");
    }
}

void push()
{
    if (full() == 1)
    {
        printf("Stack is OverFlow\n");
        return;
    }

    int val;
    printf("Enter Your Number: ");
    scanf("%d",&val);

    // top++;
    simple_stack[++top] = val;

    printf("%d inserted successfully\n", val);
}

void pop()
{
    if(empty() == 1) {
        printf("Stack is UnderFlow\n");
        return;
    }
    printf("%d is deleted successfully\n", simple_stack[top--]);
}

void display()
{
    if(empty() == 1)
    {
        printf("Stack is Under Flow");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", simple_stack[i]);
    }
    printf("\n");
}
