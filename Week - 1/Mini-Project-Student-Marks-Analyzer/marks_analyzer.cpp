#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    float marks[n];

    cout << "Enter the marks of each student:\n";

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Sort marks in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (marks[j] < marks[j + 1]) {
                float temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    // Calculate average
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }

    float average = sum / n;

    // Display sorted marks
    cout << "\nSorted marks: ";

    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }

    // Display top 3
    cout << "\n\nTop 3 marks:\n";

    int topStudents = (n < 3) ? n : 3;

    for (int i = 0; i < topStudents; i++) {
        cout << i + 1 << ". " << marks[i] << endl;
    }

    // Display average
    cout << fixed << setprecision(2);
    cout << "\nAverage score: " << average << endl;

    return 0;
}