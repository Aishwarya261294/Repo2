#include <stdio.h>
#define MAX 5

struct queue {
    int item[MAX];
    int front;
    int rear;
}pq;

/* Function to create an empty priority queue */

void create()
{
    pq.front = pq.rear = -1;
}

/* Function to insert value into priority queue */

void insert(int data)
{
    if (pq.rear >= MAX - 1) {
        printf("Queue overflow no more elements can be inserted\n");
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

/* Function to check priority and place element */

void check(int data)
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
}

/* Function to delete an element from queue */

void delete(int data)
{
    int i;

    if ((pq.front==-1) && (pq.rear==-1)) {
        printf("Queue is empty no elements to delete\n");
        return;
    }

    for (i = 0; i <= pq.rear; i++) {
        if (data == pq.item[i]) {

            for (; i < pq.rear; i++) {
                pq.item[i] = pq.item[i + 1];
            }

            pq.item[i] = -99;
            pq.rear--;

            if (pq.rear == -1)
                pq.front = -1;
                return;
        }
    }
    printf("%d not found in queue to delete\n", data);
}

/* Function to display queue elements */

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

    printf("1 - Insert an element into queue\n");
    printf("2 - Delete an element from queue\n");
    printf("3 - Display queue elements\n");
    printf("4 - Exit\n");

    create();

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
            printf("Enter value to delete : \n ");
            scanf("%d",&n);

            delete(n);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);

        default:
            printf("Choice is incorrect, Enter a correct choice\n");

        }
    }
    return 0;
}


