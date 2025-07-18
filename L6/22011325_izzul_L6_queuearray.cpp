/*
ID=22011325
Name: Izzul Muhaimie Bin Badrul Ikhwan
*/

#include <iostream>
using namespace std;

#define SIZE 5 // Max size of the queue

class Queue {
private:
    string data[SIZE]; // Array to hold queue elements
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(string name) {
        if (rear == SIZE - 1) {
            cout << "Queue is full (Overflow)" << endl;
            return;
        }

        if (front == -1) front = 0; // First insertion

        rear++;
        data[rear] = name;
        cout << "Inserted: " << name << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty (Underflow)" << endl;
            return;
        }

        cout << "Removed: " << data[front] << endl;
        front++;

        // Reset queue if empty after dequeue
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Display current queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Alicia");
    q.enqueue("Hamza");

    q.display();

    q.dequeue(); // remove "Ali"
    q.display();

    q.enqueue("Sarah");
    q.enqueue("Zara");
    q.enqueue("Tom"); // Should show overflow if limit reached

    q.display();

    return 0;
}
