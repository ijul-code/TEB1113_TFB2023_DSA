/*
ID=22011325
Name: Izzul Muhaimie Bin Badrul Ikhwan
*/
#include <iostream>
using namespace std;

class Node {
    public:
    string data;
    Node* next;
    Node(string data) {
        this->data = data;  
        next = nullptr;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Alicia");
    Node* node3 = new Node("Hamza");

    node1->next = node2;
    node2->next = node3;

    
    cout << "before deletion: ";
    Node* current = node1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    
    node1->next = node3; //deleting the second node
    delete node2;

    
    cout << "after deletion: ";
    current = node1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    

    
    current = node1;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
