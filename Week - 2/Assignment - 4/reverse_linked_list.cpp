#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert a node at the end
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Reverse the linked list using stack logic
void reverseUsingStack(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Count the number of nodes
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Create an array to work like a stack
    int* stack = new int[count];

    // Push all elements into the stack
    temp = head;
    int top = -1;

    while (temp != nullptr) {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    // Pop elements and put them back into the linked list
    temp = head;

    while (temp != nullptr) {
        temp->data = stack[top--];
        temp = temp->next;
    }

    delete[] stack;
}

int main() {
    Node* head = nullptr;

    int n;
    int value;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes.\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insert(head, value);
    }

    cout << "\nOriginal Linked List:\n";
    display(head);

    reverseUsingStack(head);

    cout << "\nReversed Linked List:\n";
    display(head);

    // Free memory
    Node* temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}