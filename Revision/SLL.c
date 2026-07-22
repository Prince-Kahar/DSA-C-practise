// Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp, *new;

void menu();

void insert();

void Create_node();
void InsertFromFront();
void InsertFromRear();
void InsertAtPosition();

void DeleteFromFront();
void DeleteFromRear();
void DeleteAtPosition();

void display();

int main()
{
    system("cls");
    menu();
}

void menu()
{
    int choice;
    do
    {
        printf(" ------------------- Singly Linked List Operation ------------------- \n");
        printf(" | 1. Insert                                                        | \n");
        printf(" | 2. Delete                                                        | \n");
        printf(" | 3. Display                                                       | \n");
        printf(" | 4. Exit                                                          | \n");
        printf(" -------------------------------------------------------------------- \n");
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
            printf("Comming Soon....\n");
            break;

        case 3:
            system("cls");
            display();
            break;

        case 4:
            system("cls");
            printf("Alvida\n");
            break;

        default:
            system("cls");
            printf("You Are **** \n");
        }
    } while (choice != 4);
}

void insert()
{
    int choice;
    do
    {
        printf(" ------------------------- Insert Operation ------------------------- \n");
        printf(" | 1. Insert From Front                                             | \n");
        printf(" | 2. Insert From Rear                                              | \n");
        printf(" | 3. Insert from Specific Location                                 | \n");
        printf(" | 0. Back To main menu                                             | \n");
        printf(" -------------------------------------------------------------------- \n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            InsertFromFront();
            break;

        case 2:
            system("cls");
            InsertFromRear();
            break;

        case 3:
            system("cls");
            InsertAtPosition();
            break;

        case 0:
            system("cls");
            printf("Go Back\n");
            break;

        default:
            system("cls");
            printf("You Are **** \n");
        }
    } while (choice != 0);
}

void Delete()
{
    int choice;
    do
    {
        printf(" ------------------------- Delete Operation ------------------------- \n");
        printf(" | 1. Delete From Front                                             | \n");
        printf(" | 2. Delete From Rear                                              | \n");
        printf(" | 3. Delete from Specific Location                                 | \n");
        printf(" | 0. Back To main menu                                             | \n");
        printf(" -------------------------------------------------------------------- \n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            DeleteFromFront();
            break;

        case 2:
            system("cls");
            DeleteFromRear();
            break;

        case 3:
            system("cls");
            DeleteAtPosition();
            break;

        case 0:
            system("cls");
            printf("Go Back\n");
            break;

        default:
            system("cls");
            printf("You Are **** \n");
        }
    } while (choice != 0);
}

void Create_node()
{
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Allocation is Failed\n");
        return;
    }

    int val;

    printf("Enter Your value: ");
    scanf("%d", &val);

    new->data = val;
    new->next = NULL;
}

void InsertFromFront()
{
    Create_node();
    new->next = head;
    head = new;
    printf("%d is Inserted From Front Successfullly\n", new->data);
}

void InsertFromRear()
{
    if (head == NULL)
    {
        InsertFromFront();
        return;
    }

    Create_node();
    printf("%d is Inserted From Rear Successfullly\n", new->data);
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

void InsertAtPosition()
{
    int val, pos;

    printf("Enter Position to Enter: ");
    scanf("%d", &pos);

    if (head == NULL && pos > 1)
    {
        printf("Position is out of bound\n");
        return;
    }

    else if (pos == 1)
    {
        Create_node();
        new->next = head;
        head = new;
    }

    else
    {
        Create_node();

        temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            if (temp == NULL)
            {
                system("cls");
                printf("Position is out of bound\n");
                return;
            }

            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }

    printf("%d is Inserted At %d Successfullly\n", new->data, pos);
}


void DeleteFromFront()
{
    if(head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    temp = head;
    head = temp->next;

    free(temp);
}

void DeleteFromRear()
{

}

void DeleteAtPosition()
{

}
void display()
{
    if (head == NULL)
    {
        printf("SLL is Empty");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
