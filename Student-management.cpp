#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string course;
    long long contact;

    void input() {
        cout << "Enter student Roll number: ";
        cin >> rollNo;
        cin.ignore(); // clear newline

        cout << "Enter student Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Contact number: ";
        cin >> contact;
        cin.ignore(); // clear newline again
    }

    void display() {
        cout << "Student Roll number: " << rollNo << endl;
        cout << "Student Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Contact number: " << contact << endl;
        cout << "---------------------------------\n";
    }
};

void addStudent() {
    Student s1;
    s1.input();

    ofstream file("Student_data.txt", ios::app);
    file << s1.rollNo << " | " << s1.name << " | " << s1.course << " | " << s1.contact << endl;
    file.close();

    cout << "\nStudent record added successfully!\n";
}

void displayStudent() {
    ifstream file("Student_data.txt");
    if (!file) {
        cout << "\nNo record found!\n";
        return;
    }

    cout << "\n---------- All Student Records ----------\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n========== Student Management System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore(); // clear leftover newline after number input

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            cout << "\nExiting program...\n";
            break;
        default:
            cout << "\nEnter valid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
