#include <stdio.h>
#define MAXQUEUE 4
#define TRUE 1
#define FALSE 0

struct queue {
    int items[MAXQUEUE];
    int front, rear;
}q;
q.front = MAXQUEUE-1;
q.rear = MAXQUEUE-1;

int delete()
{
    if(isempty()){
        printf("Queue underflow\n");
    return;
    }
    if(q.front == MAXQUEUE-1)
        q.front = 0;
    else
        q.front++;

    return (q.items[q.front]);
}

void insert()
{
    int x;

    if(q.rear == MAXQUEUE-1)
        q.rear = 0;
    else
        q.rear++;

    if(q.rear == q.front){
        printf("Queue overflow");
        return;
    }
    printf("%d %d", q.rear, q.front);
    printf("Insert the element in queue : ");
    scanf("%d", &x);

    q.items[q.front]=x;

    return;
}

int isempty()
{
    return ((q.front == q.rear)? TRUE: FALSE);
}

int display()
{
    int i;

    if (isempty()) {
        printf("Queue is empty \n");
        return;
    } else {
        printf("Queue is : \n");

        if(q.rear < q.front) {
            for (i = 0; i <= q.rear; i++) {
                printf("%d ", q.items[i]);
            }

            for (i = q.front; i <= MAXQUEUE - 1; i++) {
                printf("%d", q.items[i]);
            }
        }

        if(q.rear > q.front) {
            for(i = q.front; i <= q.rear; i++)
                printf("%d", q.items[i]);
        }
    }

    return 0;
}


int main()
{
    int choice;

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


