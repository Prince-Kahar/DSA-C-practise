/*

Q3. Singly Linked List (20 Marks)
    1. Create a Linked List with 5 nodes.
    2. Insert a new node at the Beginning.
    3. Delete a node by value.
    4. Display the updated Linked List.
    5. Bonus: Search a given element in the Linked List and display the total number of nodes.

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *new, *head, *temp, *prev;

void menu();

void createNode();
void insert();
void delete();
void display();
void Bonus();

int main()
{
    system("cls");
    menu();
}

void menu()
{
    int ch;
    do
    {
        printf(" ----------------- SLL Operations ----------------- \n");
        printf(" | 1. Insert From front                           | \n");
        printf(" | 2. Delete by Value                             | \n");
        printf(" | 3. Display                                     | \n");
        printf(" | 4. Bonus                                       | \n");
        printf(" | 5. Exit                                        | \n");
        printf(" -------------------------------------------------- \n");

        printf("Enter Your choice (1 - 5): ");
        scanf("%d", &ch);

        switch (ch)
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
            Bonus();
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

void createNode()
{
    new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("Singly Linked List is Not Allocated ... \n");
        return;
    }

    int val;

    printf("Enter your value:");
    scanf("%d", &val);

    new->data = val;
    new->next = NULL;
}

void insert()
{
    createNode();
    new->next = head;
    head = new;

    printf(" %d is inserted successfully ... \n", head->data);
}

void delete()
{
    int val;
    printf("Enter your Value To delete: ");
    scanf("%d", &val);

    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("%d is deleted successfully ... \n", val);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("%d is not found for delete ... \n", val);
}

void display()
{
    if (head == NULL)
    {
        printf("Singly Linked List is Empty ... \n");
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

void Bonus()
{
    int val, count = 0;

    printf("Enter the value for search: ");
    scanf("%d", &val);

    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            printf("%d is found successfully ... \n", val);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("%d is not found ... \n", val);

    printf("Total Node is %d ... \n",count);
}
