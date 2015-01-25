#include <iostream>
#include <cstdio>
#define MAX 100

using namespace std;

struct queue
{
    int front;
    int rear;
    int item[MAX];
}q2;

void push (struct queue *q, int x)
{
    q->rear = q->rear + 1;

    q->item[q->rear] = x;

    return;
}

void pop (struct queue *q)
{
    int i;
    int y;
    int d;

    q2.front = 0;
    q2.rear = -1;

    d = 0;

    for (i = q->rear; i >= q->front; i--) {
        d++;
    }

    for (i = 0; i < d - 1; i++) {
                    y = q->item[(q->front)++];
                    q2.rear++;
                    q2.item[q2.rear] = y;
    }

    q->rear = -1;
    q->front = 0;


    for (i = 0; i < d - 1; i++) {
                    y = q2.item[q2.front];
                    q->rear++;
                    q->item[q->rear] = y;
                    q2.front++;
    }

    q2.rear = -1;
    q2.front = 0;

}

void display (struct queue *q)
{
    int i;

    //cout << q->item[q->front];
    for (i = q->rear; i >= q->front; i--) {
                   cout << q->item[i];
    }

    cout << "\n";
}

int main()
{
    int i;
    int x;
    int y;

    struct queue q1;

    q1.front = 0;
    q1.rear = -1;

    for(i = 0; i >= 0; i++) {
            cout << "1. push \n2. pop \n0. stop";

            cin >> x;

            if(x == 1) {

                    cin >> y;
                    push (&q1, y);
                    display (&q1);
            } else if(x == 2) {
                    pop (&q1);
                    display (&q1);
            } else if (x ==0) {
                    break;
            }
    }

    display (&q1);

    return 0;
}
