#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert a node at the end
void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        cout << "Node inserted successfully.\n";
        return;
    }

    // Traverse to the last node
    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

// Delete the first node containing the given value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Linked list is empty.\n";
        return;
    }

    // If the head node contains the value
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Node deleted successfully.\n";
        return;
    }

    Node* current = head;

    while (current->next != nullptr &&
           current->next->data != value) {
        current = current->next;
    }

    // Value not found
    if (current->next == nullptr) {
        cout << "Value not found in the linked list.\n";
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    cout << "Node deleted successfully.\n";
}

// Display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty.\n";
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

// Free dynamically allocated memory
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int choice;
    int value;

    do {
        cout << "\n===== Singly Linked List =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(head, value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    // Release allocated memory
    deleteList(head);

    return 0;
}