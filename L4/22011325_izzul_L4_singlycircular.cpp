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

class SinglyCircularLinkedList {
public:
    Node* head;
    Node* tail;

    SinglyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add a node at the end
    void add_element(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            tail->next_ptr = head;  // circular: last node points to head
        } else {
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head;  // maintain circular structure
        }
    }

    // Display the list
    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "List: ";
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head: " << head->name << ")" << endl;
    }

    // Destructor to free memory
    ~SinglyCircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head;
        do {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        } while (current != head);
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    cout << "Singly Circular Linked List" << endl;
    SinglyCircularLinkedList list;

    list.add_element("Ali");
    list.add_element("Ahmed");
    list.add_element("Alee");
    list.add_element("Hamza");

    list.display_list();

    return 0;
}