#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    string className;
    float marks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Class: ";
        getline(cin, className);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nClass: " << className;
        cout << "\nMarks: " << marks << endl;
    }
};

vector<Student> students;

/* Function Prototypes */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void loadFromFile();
void saveToFile();

int main() {
    int choice;
    loadFromFile();

    do {
        cout << "\n\n===== Student Management System =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: displayStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateStudent(); break;
        case 5: deleteStudent(); break;
        case 6: saveToFile(); cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

/* Function Definitions */

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No records found!\n";
        return;
    }
    for (auto &s : students)
        s.display();
}

void searchStudent() {
    int r;
    cout << "Enter Roll No to search: ";
    cin >> r;

    for (auto &s : students) {
        if (s.roll == r) {
            s.display();
            return;
        }
    }
    cout << "Student not found!\n";
}

void updateStudent() {
    int r;
    cout << "Enter Roll No to update: ";
    cin >> r;

    for (auto &s : students) {
        if (s.roll == r) {
            cout << "Enter new details:\n";
            s.input();
            cout << "Record updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int r;
    cout << "Enter Roll No to delete: ";
    cin >> r;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->roll == r) {
            students.erase(it);
            cout << "Record deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void loadFromFile() {
    ifstream file("students.dat", ios::binary);
    if (!file) return;

    Student s;
    while (file.read((char*)&s, sizeof(s)))
        students.push_back(s);

    file.close();
}

void saveToFile() {
    ofstream file("students.dat", ios::binary);
    for (auto &s : students)
        file.write((char*)&s, sizeof(s));
    file.close();
}