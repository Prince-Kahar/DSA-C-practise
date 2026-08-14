#include <stdio.h>
#include <stdlib.h>

struct Circular
{
    int data;
    struct Circular *next;
} *new, *head, *temp, *prev, *temp2;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu();

void createNode();

void insert();
void insertFromFront();
void insertFromRear();
void insertPos();

void delete();
void deleteSingleNode();
void deleteFromFront();
void deleteFromRear();
void deletePos();

void display();

int main()
{
    clearScreen();
    menu();
}

void createNode()
{
    new = (struct Circular *)malloc(sizeof(struct Circular));
    if (new == NULL)
    {
        printf("Allocation is Failed\n");
        return;
    }
}

void menu()
{
    int choice;

    do
    {

        printf(" ---------------------- Circular Singly List Operations ---------------------- \n");
        printf(" | 1. Insert                                                                 | \n");
        printf(" | 2. Delete                                                                 | \n");
        printf(" | 3. Display                                                                | \n");
        printf(" | 4. Exit                                                                   | \n");
        printf(" ----------------------------------------------------------------------------- \n");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            insert();
            break;

        case 2:
            clearScreen();
            delete();
            break;

        case 3:
            clearScreen();
            display();
            break;

        case 4:
            clearScreen();
            printf("Byyyy \n");
            return;

        default:
            clearScreen();
            printf("You Have Chyhode Wrong Operations ... \n");
        }
    } while (choice != 4);
}

void insert()
{
    int choice;

    do
    {
        printf(" ----------------- Insert Operations ----------------- \n");
        printf(" | 1. Insert From Front                              | \n");
        printf(" | 2. Insert From Rear                               | \n");
        printf(" | 3. Insert From Spcific Location                   | \n");
        printf(" | 0. Go back                                        | \n");
        printf(" ----------------------------------------------------- \n");

        printf("Enter Your Insert choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            insertFromFront();
            break;

        case 2:
            clearScreen();
            insertFromRear();
            break;

        case 3:
            clearScreen();
            insertPos();
            break;

        case 0:
            clearScreen();
            printf("Byyy \n");
            break;

        default:
            clearScreen();
            printf("You Have Choose Wrong operations ... \n");
            break;
        }

    } while (choice != 0);
}

void insertFromFront()
{
    int val;

    printf("Enter Your Value: ");
    scanf("%d", &val);

    createNode();

    new->data = val;

    if (head == NULL)
    {
        head = new;
        new->next = head;
        printf("%d is inserted Successfully \n", val);
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = head;
    temp->next = new;

    head = new;

    printf("%d is inserted Successfully \n", val);
}

void insertFromRear()
{
    int val;

    printf("Enter Your Value: ");
    scanf("%d", &val);

    createNode();
    new->data = val;

    if (head == NULL)
    {
        head = new;
        new->next = head;
        printf("%d is inserted Successfully \n", val);
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = head;

    printf("%d is inserted Successfully \n", val);
}

void insertPos()
{
    int val, pos, count = 0;

    printf("Enter Your Position: ");
    scanf("%d", &pos);

    if (head == NULL && pos > 1)
    {
        printf("Posotion is out of bound ... \n");
        return;
    }

    else if (head == NULL && pos == 1)
    {
        insertFromFront();
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++;

    printf("Count : %d", count);

    if (pos >= count + 2)
    {
        printf("Posotion is out of bound ... \n");
        return;
    }

    else if (pos == count + 1)
    {
        insertFromRear();
        return;
    }

    createNode();

    printf("Enter Your Value: ");
    scanf("%d", &val);

    new->data = val;

    temp = head;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = new;
    new->next = temp;
}

void delete()
{
    int choice;

    do
    {
        printf(" ----------------- Delete Operations ----------------- \n");
        printf(" | 1. Delete From Front                              | \n");
        printf(" | 2. Delete From Rear                               | \n");
        printf(" | 3. Delete From Spcific Location                   | \n");
        printf(" | 0. Go back                                        | \n");
        printf(" ----------------------------------------------------- \n");

        printf("Enter Your Delete choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            deleteFromFront();
            break;

        case 2:
            clearScreen();
            deleteFromRear();
            break;

        case 3:
            clearScreen();
            deletePos();
            break;

        case 0:
            clearScreen();
            printf("Byyy \n");
            break;

        default:
            clearScreen();
            printf("You Have Choose Wrong operations ... \n");
            break;
        }

    } while (choice != 0);
}

void deleteSingleNode()
{
    printf("%d is deleted successfully ... \n", head->data);
    free(head);
    head = NULL;
    return;
}

void deleteFromFront()
{
    if (head == NULL)
    {
        printf("Circular Linked List is Empty ... \n");
        return;
    }

    if (head->next == head)
    {
        deleteSingleNode();
        return;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp2 = head;
    head = head->next;

    temp->next = head;
    printf("%d is deleted successfully ... \n", temp2->data);
    free(temp2);
    return;
}

void deleteFromRear()
{
    if (head == NULL)
    {
        printf("Circular Linked List is Empty ... \n");
        return;
    }

    if (head->next == head)
    {
        deleteSingleNode();
        return;
    }

    temp = head;
    prev = NULL;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    printf("%d is deleted successfully ... \n", temp->data);
    free(temp);
    return;
}

void deletePos()
{
    int pos, count = 0;

    if (head == NULL)
    {
        printf("Circular Linked List is Empty ... \n");
        return;
    }

    printf("Enter Your Position: ");
    scanf("%d", &pos);

    temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++;

    if (pos < 1 || pos > count)
    {
        printf("Position is out of bound ... \n");
        return;
    }

    if (pos == 1)
    {
        deleteFromFront();
        return;
    }

    if (pos == count)
    {
        deleteFromRear();
        return;
    }

    temp = head;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    printf("%d is deleted successfully ... \n", temp->data);
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("Circular Linked List is Empty ... \n");
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}
