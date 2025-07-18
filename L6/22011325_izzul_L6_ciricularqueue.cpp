/*
ID=22011325
Name: Izzul Muhaimie Bin Badrul Ikhwan
*/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {  // Queue is empty
            front = rear = new_node;
            rear->next_ptr = front;  // Circular link
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
            rear->next_ptr = front;  // Maintain circular link
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {  // Only one node
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next_ptr;
            rear->next_ptr = front;
            delete temp;
        }
    }

    // Peek at the front
    string peek() const {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return "";
        }
        return front->name;
    }

    // Display all elements
    void display_queue() const {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        do {
            cout << current->name;
            current = current->next_ptr;
            if (current != front)
                cout << " -> ";
        } while (current != front);
        cout << " (back to front: " << front->name << ")" << endl;
    }

    // Check if queue is empty
    bool is_empty() const {
        return front == nullptr;
    }

    // Destructor
    ~CircularQueue() {
        if (front == nullptr)
            return;

        Node* current = front;
        do {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        } while (current != front);

        front = rear = nullptr;
    }
};
int main() {
    CircularQueue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");

    queue.display_queue();  // Ali -> Ahmed -> Alee

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.display_queue();  // Ahmed -> Alee

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();  // Extra dequeue to show empty state

    return 0;
}
