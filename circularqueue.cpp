#include <iostream>
#define MAXSIZE 6

using namespace std;

struct circular {
    int front;
    int rear;
    int arr[MAXSIZE];
} c;

void enqueue(int x) {
    if ((c.front == c.rear + 1) || (c.rear == MAXSIZE - 1 && c.front == 0)) {
        cout << "overflow";
        c.rear = -1;
        return;
    }

    if (c.front == -1) {
        c.front = 0;
    }

    if (c.rear == MAXSIZE - 1) {
        c.rear = 0;
    } else {
        c.rear++;
    }

    c.arr[c.rear] = x;
}

int dequeue() {
    if (c.front == -1) {
        cout << "underflow";
        return 0;
    }

    if (c.front == c.rear){
        int x = c.arr[c.front];
        c.front = c.rear = -1;
        return x;
    } else {
        return c.arr[c.front++];
    }
}

void display() {
    int i;

    if (c.rear < c.front) {
        for (i = 0; i <= c.rear; i++) {
            cout << c.arr[i];
        }

        for (i = c.front; i <= MAXSIZE - 1; i++) {
            cout << c.arr[i];
        }
    } else if (c.rear > c.front) {
        for (i = c.front; i <= c.rear; i++) {
            cout << c.arr[i];
        }
    } else if ((c.rear == c.front) != -1) {
            cout << c.arr[c.rear];
    } else {
        cout << "no elements to display\n";
        return;
    }
}

int main()
{
    int option = 1;
    c.front = -1;
    c.rear  = -1;
    int ch;
    int i;
    int x;

    cout << "choose from 1: enqueue 2: dequeue 3:display ";

    while (option) {
        cin >> ch;
        switch(ch) {
        case 1: cin >> x;
                enqueue(x);
                break;
        case 2: cout << dequeue();
                break;
        case 3: display();
                break;
    }
        cout << "press 1 to continue and 0 to discontinue";
        cin >> option;
    }

    return 0;
}
