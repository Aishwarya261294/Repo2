#include <stdio.h>
#define MAX 4

struct queue
{
    int item[MAX];
    int front, rear;
} p;

int insert()
{
    int add;

    if(p.rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (p.front == -1)
            p.front = 0;
    }

    printf("Insert the element in queue : ");
    scanf("%d", &add);

    (p.rear)++;
    p.item[p.rear] = add;

    return 0;
}

int delete()
{
    if (p.front == - 1 || (p.front) > (p.rear))
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Element deleted from queue is : %d\n", p.item[p.front]);

        (p.front)++;
    }
    return 0;
}

int display()
{
    int i;

    if (p.front == - 1)
        printf("Queue is empty \n");

    else
    {
        printf("Queue is : \n");

        for (i = p.front; i <= p.rear; i++)
            printf("%d ", p.item[i]);
        printf("\n");
    }
    return 0;
}


int main()
{
    int choice;
    p.rear = p.front = -1;

    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 5:
            return;

        default:
            printf("Wrong choice \n");

        }
    }
    return 0;
}
