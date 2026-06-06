#include <stdio.h>
#include <stdlib.h>

struct Singly
{
    int info;
    struct Singly *next;
} *head = NULL, *node, *temp;

int count = 0;

void insert();
void insertFromFront();
void insertFromRear();
void display();

int main()
{

    int choice;
    system("cls");
    do
    {
        printf(" ====> Singly Linked List <====\n");
        printf(" 1. Insert\n");
        printf(" 2. Display\n");
        printf(" 3. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            insert();
            break;

        case 2:
            system("cls");
            display();
            break;
        case 3:
            system("cls");
            printf("Exiting\n");
            break;

        default:
            system("cls");
            printf("Invalid Choice\n");
        }
    } while (choice != 3);
    return 0;
}

void insert()
{
    int choice;
    do
    {
        printf(" ===> Insert Menu <==== \n");
        printf(" 1. Insert From front \n");
        printf(" 2. Insert From Rear \n");
        printf(" 3. Back to main menu \n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            insertFromFront();
            break;

        case 2:
            system("cls");
            insertFromRear();
            break;

        case 3:
            system("cls");
            printf("Go back ! I said Go back....\n");
            break;

        default:
            system("cls");
            printf("Invalid Choice\n");
        }
    } while (choice != 3);
}

void insertFromFront()
{
    int val;

    node = (struct Singly *)malloc(sizeof(struct Singly));
    if (node == NULL)
    {
        printf("Initialization Failed...\n");
        return;
    }

    printf("Enter a value for insert From Front: ");
    scanf("%d", &val);

    node->info = val;
    node->next = head;
    head = node;

    count++;

    printf(" Inserted From Front Successfully...\n");
}

void insertFromRear()
{
    int count1 = 1;
    int val;

    struct Singly *Snode = (struct Singly *)malloc(sizeof(struct Singly));
    struct Singly *temp1;

    if (node == NULL)
    {
        printf("Initialization Failed...\n");
        return;
    }

    printf("Enter a value for insert From Rear: ");
    scanf("%d", &val);

    Snode->info = val;
    Snode->next = NULL;
    do
    {
        temp = node->next;
        printf("Count = %d count1 = %d\n", count, count1);
        // if (count1 == count)
        // {
        //     temp->next = Snode;
        //     count++;
        //     count1++;
        //     printf("Count = %d count1 = %d\n", count , count1);
        //     printf(" Inserted From Rear Successfully...\n");
        //     break;
        // }
        // else
        count1++;
    } while (node -> next != NULL);
    count++;
}

void display()
{
    int count1 = 1;
    if (head == NULL)
    {
        printf(" Singly Linked List is Empty\n");
        return;
    }
    temp = head;
    do
    {

        printf("  %d", temp->info);
        temp = temp->next;
        count1++;

    } while (count1 <= count);
}
