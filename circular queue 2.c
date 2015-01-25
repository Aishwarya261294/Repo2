#include <stdio.h>
#define MAX 100

struct queue {
    int cq[MAX];
    int front;
    int rear;
}q;

void enqueue()
{
    int x;
    printf("The element to be Inserted:\n");
    scanf("%d", &x);

    if (cqfull()) {
        printf("Overflow\n");
    } else {
        if (q.front == -1)
            q.front = 0;
            q.rear = (q.rear+ 1) % MAX;
            q.cq[q.rear] = x;
    }
}

int dequeue()
{
    int x;

    if (cqempty()) {
        printf("Underflow\n");
        return (-1);
    } else {
        x = q.cq[q.front];

        if (q.front == q.rear) {
            q.front = -1;
            q.rear = -1;       /* Q has only one element ? */
        } else {
            q.front = (q.front + 1) % MAX;
            return (x);
        }
    }
}

int cqfull()
{
    if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == MAX - 1))
        return 1;

    return 0;
}

int cqempty()
{
    if (q.front == -1)
        return 1;

    return 0;
}

void display()
{
    int i;

    if (cqempty()) {
        printf("Empty Queue\n");
    } else {
        printf("Front[%d]->", q.front);

        for (i = q.front; i != q.rear; i = (i + 1) % MAX)
            printf("%d ", q.cq[i]);
            printf("%d ", q.cq[i]);
            printf("<-[%d]Rear", q.rear);
    }
}

int main()
{
    int choice;
    int elem;

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
            enqueue();
            break;

        case 2:
            elem = dequeue();
            if (elem != -1)
            printf("Deleted Element is %d \n", elem);
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
