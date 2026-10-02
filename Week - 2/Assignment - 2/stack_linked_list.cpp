#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Push an element onto the stack
void push(Node*& top, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << "Element pushed successfully.\n";
}

// Pop the top element
void pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    Node* temp = top;

    cout << "Popped element: " << top->data << endl;

    top = top->next;

    delete temp;
}

// View the top element
void peek(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element: " << top->data << endl;
}

// Display the stack
void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack: ";

    Node* temp = top;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Free all allocated memory
void deleteStack(Node*& top) {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    Node* top = nullptr;

    int choice;
    int value;

    do {
        cout << "\n===== Stack Using Linked List =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(top, value);
                break;

            case 2:
                pop(top);
                break;

            case 3:
                peek(top);
                break;

            case 4:
                display(top);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    deleteStack(top);

    return 0;
}