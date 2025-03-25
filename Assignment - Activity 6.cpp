#include <iostream>
#include <string>
#define MAX_STUDENTS 10000
using namespace std;

struct Student {
    int studentid;
    string studentname1;
    string studentname2;
    float gpa;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

int findingstudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentid == id) {
            return i;
        }
    }
    return -1;
}

void Addingstudents() {
    if (studentCount >= MAX_STUDENTS) {
        cout << " " << endl;
        cout << "Student List is Full" << endl;
        return;
    }

    Student stdnt;
    cout << " " << endl;
    cout << "Please Enter Student ID: ";
    cin >> stdnt.studentid;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentid == stdnt.studentid) {
            cout << "Duplicate ID Found! Please Try Again." << endl;
            cout << " " << endl;
            return;
        }
    }
    cout << "Please Enter Student Name [First Name]: ";
    cin >> stdnt.studentname1;
    cout << "Please Enter Student Name [First Name]: ";
    cin >> stdnt.studentname2;
    cout << "Please Enter GPA: ";
    cin >> stdnt.gpa;
    cout << " " << endl;


    students[studentCount++] = stdnt;
    cout << "Student Successfully Added!" << endl;
    cout << " " << endl;
}

void editingstudents() {
    int id;
    string pick;
    cout << " " <<endl;
    cout << "Please Enter Student ID to Edit: ";
    cin >> id;

    int index = findingstudent(id);
    if (index == -1) {
        cout << "Student Not Found!" << endl;
        return;
    }

    cout << endl << "Student Details:" << endl;
    cout << "ID: " << students[index].studentid << endl;
    cout << "Name: " << students[index].studentname1 << " " << students[index].studentname2 << endl;
    cout << "GPA: " << students[index].gpa << endl;
    cout << endl;

    cout << "Do you want to Edit Student Data? (yes/no): ";
    cin >> pick;

    if (pick == "yes") {
        int choice;
        do {
            cout << "What do you want to change?" << endl;
            cout << "[1] ID" << endl;
            cout << "[2] Name" << endl;
            cout << "[3] GPA" << endl;
            cout << "[4] Exit" << endl;
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1:{
                    int newID;
                    cout << "Enter New ID: ";

                    while (true) {
                    cin >> newID;
                    int i;

                    for (i = 0; i < studentCount; i++) {
                        if (students[i].studentid == newID) {
                        cout << "Error: ID already exists! Please enter a unique ID: ";
                        break;
                        }
                        }

                        if (i == studentCount) {
                        students[index].studentid = newID;
                        break;
                        }}
                        break;}

                case 2:
                    cout << "Enter New Name [First Name]: ";
                    cin >> students[index].studentname1;
                    cout << "Enter New Name [Last Name]: ";
                    cin >> students[index].studentname2;
                    break;

                case 3:
                    cout << "Enter New GPA: ";
                    cin >> students[index].gpa;
                    break;

                case 4:
                    cout << "Returning...." << endl;
                    break;

                default:
                    cout << "Invalid Input!" << endl;
            }

            cout << endl << "Updated Student Details:" << endl;
            cout << "ID: " << students[index].studentid << endl;
            cout << "Name: " << students[index].studentname1 << " " << students[index].studentname2 << endl;
            cout << "GPA: " << students[index].gpa << endl;
            cout << " " << endl;
            cout << "Student Information Updated Successfully!" << endl;

        } while (choice != 4);
    }
}


void deletingstudent() {
    int id;
    string pick;
    cout << " " << endl;
    cout << "Enter Student ID To Delete: ";
    cin >> id;

    int index = findingstudent(id);
    if (index == -1) {
        cout << "Student Not Found!" << endl;
        return;
    }
    cout << " " << endl;
    cout << endl << "Student Details:" << endl;
    cout << "ID: " << students[index].studentid << endl;
    cout << "Name: " << students[index].studentname1 << " " << students[index].studentname2 << endl;
    cout << "GPA: " << students[index].gpa << endl;
    cout << " " << endl;

    cout << "Delete? [yes/no]" << endl;
    cin >> pick;


    if (pick == "yes")
    {
    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;

    cout << "Student Deleted Successfully!" << endl;
    }
    else
    {
        return;
    }
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "No student records available." << endl;
        return;
    }

    cout << " " << endl;
    cout << "View students by:" << endl;
    cout << "1. Alphabetically by Name" << endl;
    cout << "2. By GPA (ascending)" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    Student temp[MAX_STUDENTS];
    for (int i = 0; i < studentCount; i++) {
        temp[i] = students[i];
    }

    if (choice == 1) {
        for (int i = 0; i < studentCount - 1; i++) {
            for (int j = 0; j < studentCount - i - 1; j++) {
                if (temp[j].studentname1 > temp[j + 1].studentname1) {
                    swap(temp[j], temp[j + 1]);
                }
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < studentCount - 1; i++) {
            for (int j = 0; j < studentCount - i - 1; j++) {
                if (temp[j].gpa > temp[j + 1].gpa) {
                    swap(temp[j], temp[j + 1]);
                }
            }
        }
    } else {
        cout << " " << endl;
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << " " << endl;
    cout << "Student List: " << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << temp[i].studentid << ", Name: " << temp[i].studentname1 << " " << temp[i].studentname2 << ", GPA: " << temp[i].gpa << endl;
    }
}

int main() {
    int menu;
    do {
        cout << " " << endl;
        cout << "=========================" << endl;
        cout << "Menu" << endl;
        cout << "[1] Add Student" << endl;
        cout << "[2] Edit Student" << endl;
        cout << "[3] Delete Student" << endl;
        cout << "[4] View Students" << endl;
        cout << "[5] Exit Program" << endl;
        cout << "========================="<< endl;
        cout << "Enter choice: ";
        cin >> menu;


        switch (menu) {
            case 1: Addingstudents();
                    break;
            case 2: editingstudents();
                    break;
            case 3: deletingstudent();
                    break;
            case 4: displayStudents();
                    break;
            case 5: cout << "Exiting...." << endl;
                    break;
            default: cout << "Invalid Choice! Please choose again." << endl;
        }
    } while (menu != 5);

    return 0;
}
