#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
    int marks[5];   // assuming 5 subjects

public:
    // Function to input details
    void input() {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter marks of 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    // Recursive function to calculate total marks
    int totalMarks(int arr[], int n) {
        if (n == 0)
            return 0;
        return arr[n - 1] + totalMarks(arr, n - 1);
    }

    // Function to display details
    void display() {
        cout << "\nName: " << name << endl;
        cout << "Roll Number: " << roll << endl;

        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }

        int total = totalMarks(marks, 5);
        cout << "\nTotal Marks: " << total << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Dynamic memory allocation
    Student *s = new Student[n];

    // Input details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        s[i].input();
    }

    // Display details
    cout << "\n--- Student Details ---" << endl;
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    // Free memory
    delete[] s;

    return 0;
}