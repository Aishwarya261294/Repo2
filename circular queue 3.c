#include <stdio.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

struct queue {
    int items[MAX];
    int front, rear;
}q;

int delete()
{
    int x;

    if (q.front == -1)
        printf("Queue is empty\n");
    else {
        x = q.items[q.front];

        if (q.front == q.rear) {
            q.front = -1;
            q.rear = -1;
        }
        else
            if (q.front == MAX - 1)
                q.front  = 0;
            else
                q.front++;
    }
    return x;
}

void insert()
{
    int x;

    if ((q.front == 0 && q.rear == MAX - 1)|| (q.front == q.rear + 1))
        printf("Queue is full\n");

    else {
        printf("Enter the element to enqueue:\n");
        scanf("%d", &x);

        if (q.rear == -1) {
            q.rear = 0;
            q.front = 0;
        }
        else
            if (q.rear == MAX - 1)
                q.rear = 0;
            else
                q.rear++;
    }
    q.items[q.rear] = x;
    return;
}

int isempty()
{
    return ((q.front == q.rear)? TRUE: FALSE);
}

int display()
{
    int i;

    if ((q.front == -1)|| (q.front = q.rear + 1))
        printf("Queue is empty\n");

    else {
        for (i = 0; i <=  q.rear; i++) {
            printf("%d", q.items[i]);
        }
    }
}

int main()
{
    int choice;
    q.rear = -1;
    q.front = -1;

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
