/*
ID=22011325
Name: Izzul Muhaimie Bin Badrul Ikhwan
*/
#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    // Recursively search for a node by name
    Node* find_node(Node* current, const string& name) {
        if (!current) return nullptr;
        if (current->name == name) return current;

        Node* found = find_node(current->left, name);
        if (found) return found;

        return find_node(current->right, name);
    }

    // Add left child to parent by name
    void add_left(string parent_name, string child_name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            if (!parent->left)
                parent->left = new Node(child_name);
            else
                cout << "Left child already exists for " << parent_name << endl;
        } else {
            cout << "Parent not found: " << parent_name << endl;
        }
    }

    // Add right child to parent by name
    void add_right(string parent_name, string child_name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            if (!parent->right)
                parent->right = new Node(child_name);
            else
                cout << "Right child already exists for " << parent_name << endl;
        } else {
            cout << "Parent not found: " << parent_name << endl;
        }
    }
};


int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");

    // Manual check
    cout << "Root: " << tree.root->name << endl;
    cout << "Left of A: " << tree.root->left->name << endl;
    cout << "Right of A: " << tree.root->right->name << endl;

    return 0;
}
