#include <iostream>
#define MAX 5
using namespace std;

class cqueuepizza {
    int q[MAX], rear, front;

public:
    cqueuepizza();
    void insert(int);
    int delete1();
    void display();
};

cqueuepizza::cqueuepizza() {
    front = rear = -1;
}

void cqueuepizza::insert(int value) {
    if (((rear == MAX - 1) && (front == -1)) || (rear - front) == -1) {
        /*
        Reference : Fundamentals of Data Structures in C
        by Horowitz, Sahani, Freed. Page 116
        To distinguish queue full and queue empty (as both have FRONT = REAR),
        Queue full allows MAX - 1 elements, rather than MAX
        */
        cout << "\nQueue is Full";
    } else {
        if (rear == MAX - 1) { // creating circular link
            rear = -1;
        }
        rear++;
        q[rear] = value;
        cout << "Order added at " << rear << endl;
    }
}

int cqueuepizza::delete1() {
    int value;
    if (rear == front) {
        cout << endl << "Queue is Empty";
        return -999;
    } else {
        if ((front == MAX - 1) && rear < front) { // creating circular link
            front = -1;
        }
        front++;
        value = q[front];
        cout << "Order removed from " << front << endl;
        return value;
    }
}

void cqueuepizza::display() {
    int i;
    cout << endl;

    if (front <= rear) {
        i = front + 1;
        while (i <= rear) {
            cout << q[i++] << "  ";
        }
    } else {
        i = front + 1;
        while (i <= MAX - 1) {
            cout << q[i++] << "  ";
        }
        i = 0;
        while (i <= rear) {
            cout << q[i++] << "  ";
        }
    }
}

int main() {
    int choice, x, y;
    char ans;
    cqueuepizza q1;

    do {
        cout << "\n*****MENU*****";
        cout << "\n1. Place an order id ";
        cout << "\n2. Remove an order id ";
        cout << "\n3. Display the queue ";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the order id: ";
                cin >> y;
                q1.insert(y);
                q1.display();
                break;

            case 2:
                x = q1.delete1();
                if (x != -999) {
                    cout << "\nThe removed order is: " << x;
                }
                q1.display();
                break;

            case 3:
                q1.display();
                break;

            default:
                cout << "\nWrong choice!!";
                break;
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> ans;

    } while (ans == 'y');

    return 0;
}
