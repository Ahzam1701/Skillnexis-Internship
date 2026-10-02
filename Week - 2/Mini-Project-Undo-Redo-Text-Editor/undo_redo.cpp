#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;

    // Stack for undo operations
    stack<string> undoStack;

    // Stack for redo operations
    stack<string> redoStack;

public:

    // Add text
    void addText(string newText) {
        undoStack.push(text);

        text += newText;

        // Clear redo stack after a new action
        while (!redoStack.empty()) {
            redoStack.pop();
        }

        cout << "Text added successfully.\n";
    }

    // Undo last action
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        redoStack.push(text);

        text = undoStack.top();
        undoStack.pop();

        cout << "Undo successful.\n";
    }

    // Redo last undone action
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }

        undoStack.push(text);

        text = redoStack.top();
        redoStack.pop();

        cout << "Redo successful.\n";
    }

    // Display current text
    void display() {
        cout << "\nCurrent Text: ";

        if (text.empty()) {
            cout << "[Empty]";
        } else {
            cout << text;
        }

        cout << endl;
    }
};

int main() {
    TextEditor editor;

    int choice;
    string input;

    do {
        cout << "\n===== Undo-Redo Text Editor =====\n";
        cout << "1. Add Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Display Text\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

            case 1:
                cout << "Enter text to add: ";
                getline(cin, input);
                editor.addText(input);
                break;

            case 2:
                editor.undo();
                break;

            case 3:
                editor.redo();
                break;

            case 4:
                editor.display();
                break;

            case 5:
                cout << "Exiting editor...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}