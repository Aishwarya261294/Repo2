#include <stdio.h>
#define MAX 5

struct queue {
    int item[MAX];
    int front;
    int rear;
}pq;

void insert(int data)
{
    if (pq.rear >= MAX - 1) {
        printf("Queue overflow\n");
        return;
    }

    if ((pq.front == -1) && (pq.rear == -1)) {
        pq.front++;
        pq.rear++;

        pq.item[pq.rear] = data;

        return;

    } else {
        check(data);
        pq.rear++;
    }
}

int check(int data)
{
    int i;
    int j;

    for (i = 0; i <= pq.rear; i++) {
        if (data >= pq.item[i]) {

                for (j = pq.rear + 1; j > i; j--) {
                    pq.item[j] = pq.item[j - 1];
                }
                pq.item[i] = data;
                return;
        }
    }
    pq.item[i] = data;

    return 0;
}

int delete()
{
    if (pq.front == - 1 || (pq.front) > (pq.rear))
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Element deleted from queue is : %d\n", pq.item[pq.front]);

        (pq.front)++;
    }
    return 0;
}

void display()
{
    if ((pq.front == -1) && (pq.rear == -1)) {
        printf("Queue is empty\n");
        return;
    }

    for (; pq.front <= pq.rear; pq.front++) {
        printf(" %d ", pq.item[pq.front]);
    }
    pq.front = 0;
}

int main()
{
    int n, ch;
    pq.front = pq.rear = -1;

    printf("1 - Insert an element into queue\n");
    printf("2 - Delete an element from queue\n");
    printf("3 - Display queue elements\n");
    printf("4 - Exit\n");

    while (1) {
        printf("Enter your choice : \n");
        scanf("%d", &ch);

        switch (ch) {

        case 1:
            printf("Enter value to be inserted :\n ");
            scanf("%d",&n);

            insert(n);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            return;

        default:
            printf("Incorrect choice\n");

        }
    }
    return 0;
}
