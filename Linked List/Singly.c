#include <stdio.h>
#include <stdlib.h>

struct Singly
{
    int info;
    struct Singly *next;
} *head = NULL, *node, *temp;

int count = 0;

void create_node();
void insert();

void insertFromFront();
void insertFromRear();
void insertBeforePos();
void insertAfterPos();

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

void create_node()
{
    int val;

    node = (struct Singly *)malloc(sizeof(struct Singly));

    if (node == NULL)
    {
        printf("Initialization Failed...\n");
        return;
    }

    printf("Enter a value for insert : ");
    scanf("%d", &val);

    count++;

    node->info = val;
    // node->next = NULL;
}

void insert()
{
    int choice;
    do
    {
        printf(" ===> Insert Menu <==== \n");
        printf(" 1. Insert From front \n");
        printf(" 2. Insert From Rear \n");
        printf(" 3. Insert Before specfic position\n");
        printf(" 4. Insert After specfic position\n");
        printf(" 5. Back to main menu \n");

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
            insertBeforePos();
            break;

        case 4:
            system("cls");
            insertAfterPos();
            break;

        case 5:
            system("cls");
            printf("Go back ! I said Go back....\n");
            break;

        default:
            system("cls");
            printf("Invalid Choice\n");
        }
    } while (choice != 5);
}

void insertFromFront()
{
    create_node();
    node->next = head;
    head = node;

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
    } while (node->next != NULL);
    count++;
}

void insertBeforePos()
{
    struct Singly *pTemp;
    int pos;

    printf("Enter position to insert before: ");
    scanf("%d", &pos);

    temp = head;
    for (int i = 1; i < pos; i++)
    {
        pTemp = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Position Not Found ... \n");
            return;
        }
    }

    create_node();
    pTemp->next = node;
    node->next = temp;

    printf("Succefully Inserted Value Before %d.... \n", pos);
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
