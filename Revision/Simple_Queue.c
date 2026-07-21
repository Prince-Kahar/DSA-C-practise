#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int front = -1, rear = -1, simple_Queue[SIZE];

void insert();
void delete();
void display();

int main()
{
    int choice;
    system("cls");

    do
    {
        printf("\n ---------------- Simpl Queue Operations ---------------- \n");
        printf(" | 1. Insert                                            | \n");
        printf(" | 2. Delete                                            | \n");
        printf(" | 3. Display                                           | \n");
        printf(" | 4. Exit                                              | \n");
        printf(" -------------------------------------------------------- \n");
        printf(" Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            insert();
            break;

        case 2:
            system("cls");
            delete();
            break;

        case 3:
            system("cls");
            display();
            break;

        case 4:
            system("cls");
            printf("Chal jaa BSDK Wapas mat aana");

        default:
            printf("Tere pass koi aur rasta nahi hain chal wapas aa fir dekhta huun");
        }
    } while (choice != 4);
}

void insert()
{
    if (rear == SIZE - 1)
    {
        printf("Queue is OverFlow");
        return;
    }

    int val;

    printf("Enter Your Value: ");
    scanf("%d", &val);

    front = 0;

    simple_Queue[++rear] = val;
    printf("Successfully inserted %d", val);
}

void delete()
{

    if (front == -1)
    {
        printf("Queue is underflow");
        return;
    }
    printf("Successfully Deletd %d", simple_Queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else
        front++;
}

void display()
{
    if (rear == -1)
    {
        printf("Queue is Empty");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d \t", simple_Queue[i]);
    }
}
