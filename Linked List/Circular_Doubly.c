#include <stdio.h>
#include <stdlib.h>

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct circularDoubly
{
    struct circularDoubly *prevAddress;
    int data;
    struct circularDoubly *nextAddress;
} *head, *new, *temp;

void menu();
void createNode();

void insert();
void insertFromFront();
void insertFromRear();

void delete();

void display();
void ForwardDisplay();
void BackwardDisplay();

int main()
{
    clearScreen();
    menu();
    return 0;
}

void menu()
{
    int choice;

    do
    {

        printf(" ----------------------- Doubly Linked List Operations ----------------------- \n");
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

void createNode()
{
    new = (struct circularDoubly *)malloc(sizeof(struct circularDoubly));

    if (new == NULL)
    {
        printf("Memory allocated failed");
        return;
    }

    int val;
    printf("Enter Your Value : ");
    scanf("%d", &val);

    new->prevAddress = NULL;
    new->data = val;
    new->prevAddress = NULL;

    printf("%d is inserted successfully ... \n", val);
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
            // insertPos();
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
    createNode();
    if (head == NULL)
    {
        new->prevAddress = new;
        new->nextAddress = new;
    }
    else
    {
        new->nextAddress = head;
        new->prevAddress = head->prevAddress;
        head->prevAddress->nextAddress = new;
    }
    head = new;
}

void insertFromRear()
{
    if (head == NULL)
        insertFromFront();
    else
    {
        createNode();
        head->prevAddress->nextAddress = new;
        new->prevAddress = head->prevAddress;
        head->prevAddress = new;
        new->nextAddress = head;
    }
}

void delete() {}

void display()
{
    int choice;

    do
    {

        printf(" ----------------------------- Display Operations ---------------------------- \n");
        printf(" | 1. Forward Display                                                        | \n");
        printf(" | 2. Backward Display                                                       | \n");
        printf(" | 3. Exit                                                                   | \n");
        printf(" ----------------------------------------------------------------------------- \n");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            ForwardDisplay();
            break;

        case 2:
            clearScreen();
            BackwardDisplay();
            break;

        case 3:
            clearScreen();
            printf("Byyyy \n");
            return;

        default:
            clearScreen();
            printf("You Have Chyhode Wrong Operations ... \n");
        }
    } while (choice != 3);
}

void ForwardDisplay()
{
    if (head == NULL)
    {
        printf("Circular Doubly Linked List is UnderFlow ... \n");
        return;
    }
    temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->nextAddress;
    } while (temp != head);
    printf("\n\n");
}

void BackwardDisplay()
{
}