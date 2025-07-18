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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (rear == nullptr) { // Empty queue
            front = rear = new_node;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next_ptr;
        delete temp;

        if (front == nullptr) { // If queue becomes empty
            rear = nullptr;
        }
    }

    // Peek at the front element
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
        while (current != nullptr) {
            cout << current->name;
            current = current->next_ptr;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }

    // Check if queue is empty
    bool is_empty() const {
        return front == nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next_ptr;
            delete temp;
        }
    }
};
int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");

    queue.display_queue();  // Queue: Ali -> Ahmed -> Alee

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    cout << "After one dequeue: ";
    queue.display_queue();  // Queue: Ahmed -> Alee

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();  // Should show empty message

    return 0;
}
