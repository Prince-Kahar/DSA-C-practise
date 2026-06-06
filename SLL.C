#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
} *head, *node, *temp;

void create_node()
{
    int val;
    node = (struct SLL *)malloc(sizeof(struct SLL));
    if (node == NULL)
    {
        printf("\n Overflow");
        return;
    }
    printf("\n Enter value=>");
    scanf("%d", &val);
    node->data = val;
    // node->next = NULL;
}

void insert_beg();
// void insert_end();
void display();

void menu()
{
    printf("\n ==>SLL<==");
    printf("\n 1.Insert");
    printf("\n 2.Display");
    printf("\n 3.Exit");
}

void insert_menu()
{
    printf("\n 1.Insert at the front");
    printf("\n 2.Insert at the end");
    printf("\n 3.Insert at the after specific position");
    printf("\n 4.Insert at the after specific value");
    printf("\n 5.Insert into sorted Linked list");
    printf("\n 6.Back to main menu");
}

int main()
{
    // system("cls");
    int ch, ch1;
    do
    {
        menu();
        printf("\n Enter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            // system("clear");
            do
            {
                insert_menu();
                printf("\n Enter your choice=>");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    // system("clear");
                    insert_beg();
                    break;

                case 2:
                    // system("clear");
                    //    / insert_end();
                    break;

                case 3:
                    // system("clear");
                    printf("Aave che");
                    break;

                case 6:
                    // system("clear");
                    break;

                default:
                    // system("clear");
                    printf("Invalid");
                }
            } while (ch1 != 6);
            break;

        case 2:
            // system("clear");
            display();
            break;

        case 3:
            // system("clear");
            printf("bye bye aavjo");
            break;

        default:
            // system("clear");
            printf("Kaik khotu che");
        }

    } while (ch != 3);
}

void insert_beg()
{
    create_node();
    node->next = head;
    head = node;
}

void display()
{
    if (head == NULL)
    {
        printf("\n SLL is empty");
    }
    else
    {
        temp = head;
        do
        {
            printf("\t %d", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
}