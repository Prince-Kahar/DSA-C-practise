/*

Q2. Queue Using Array (20 Marks)
    1. Enqueue 5 elements into the Queue.
    2. Dequeue 2 elements from the Queue.
    3. Display the updated Queue.
    4. Bonus: Display the Front and Rear elements, and calculate the sum of all elements present in the Queue.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int circularQueue[MAX], f = -1, r = -1;

void menu();
void Enqueue();
void Dequeue();
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
        printf(" ---------------- Queue Operations ---------------- \n");
        printf(" | 1. Enqueue                                     | \n");
        printf(" | 2. Dequeue                                     | \n");
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
            Enqueue();
            break;

        case 2:
            system("cls");
            Dequeue();
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

void Enqueue()
{
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        circularQueue[r] = value;
    }

    else if (r == f - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    else if (f != 0)
    {
        if (r == MAX - 1)
        {
            r = 0;
            circularQueue[r] = value;
        }
        else
            circularQueue[++r] = value;
    }
    else if (r == MAX - 1)
    {
        printf(" Queue Is Full \n");
        return;
    }

    else
        circularQueue[++r] = value;
}

void Dequeue()
{

    if (f == r)
    {
        printf(" Queue Is Empty \n");
        return;
    }

    printf("%d Deleted Successfully ... \n", circularQueue[f++]);
}

void display()
{
    if(f == r)
    {
        printf("Queue is Empty \n");
        return;
    }

    for (int i = f; i <= r; i++)
        printf("%d\t", circularQueue[i]);

    printf("\n");
}

void Bonus()
{
    printf("Front = %d\nRear = %d\n", f, r);

    int total = 0;
    for(int i = f; i <= r ; i++)
        total += circularQueue[i];

    printf("The Sum of All elemnets is %d ... \n", total);
}
