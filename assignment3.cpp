#include <iostream>
#include <vector>
#include <iomanip>
//#include <limits>
using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    float testScores[3];
    float average;
    char grade;

public:
    void inputData() {
        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Full Name: ";
        getline(cin,fullName);
        for (int i = 0; i < 3; i++) {
            cout << "Enter score " << i + 1 << ": ";
            cin>>testScores[i];
        }
        calculateAverage();
        assignGrade();
    }

    void calculateAverage() {
        average = (testScores[0] + testScores[1] + testScores[2]) / 3;
    }

    void assignGrade() {
        if (average >= 90){ grade = 'A';}
        else if (average >= 80) {grade = 'B';}
        else if (average >= 70) {grade = 'C';}
        else if (average >= 60) {grade = 'D';}
        else{ grade = 'F';}
    }

    void displayData() const {
         cout << left << setw(10) << studentID
             << setw(20) << fullName
             << setw(10) << fixed << setprecision(2) << average
             << setw(5) << grade << endl;
    }

    string getID() const { return studentID; }
    float getAverage() const { return average; }
    char getGrade() const { return grade; }
};

void displayMenu() {
    cout<< "\n====== Student Management System ======\n";
    cout<< "1. Add Student Records\n";
    cout<< "2. Display All Students\n";
    cout<< "3. Search Student by ID\n";
    cout<< "4. Top and Lowest Performer\n";
    cout<< "5. Grade Summary\n";
    cout<< "6. Exit\n";
    cout<< "=======================================\n";
    cout<< "Enter choice: ";
}

int main(){
    vector<Student> students;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        if (choice == 1){
            int j;
            cout << "Enter number of students less than 50 to add: ";
            cin >> j;
            if (j < 1 || j > 50 || students.size() + j > 50) {
                cout << "Number out of range\n";
            } else {
                for (int i = 0; i < j; i++) {
                    cout << "\n--- Enter data for student " << i + 1 << " ---\n";
                    Student s;
                    s.inputData();
                    students.push_back(s);
                    }
                }
            }else if (choice == 2) {
            if (students.empty()) {
                cout << "Student database empty. \n";
            } else {
                cout << left << setw(10) << "ID"
                     << setw(20) << "Name"
                     << setw(10) << "Average"
                     << setw(5) << "Grade" << endl;
                for (const auto& s : students) {
                    s.displayData();
                }
            }
        }else if (choice == 3) {
            if (students.empty()) {
                cout << "Student database empty.\n";
            } else {
                string id;
                cout << "Enter student ID to search: ";
                cin >> id;
                bool found = false;
                for (const auto& s : students) {
                    if (s.getID() == id) {
                        cout << left << setw(10) << "ID"
                             << setw(20) << "Name"
                             << setw(10) << "Average"
                             << setw(5) << "Grade" << endl;
                        s.displayData();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            if (students.empty()) {
                cout << "Student database empty.\n";
            } else {
                const Student* top = &students[0];
                const Student* low = &students[0];
                for (const auto& s : students) {
                    if (s.getAverage() > top->getAverage())
                        top = &s;
                    if (s.getAverage() < low->getAverage())
                        low = &s;
                }

                cout << "\n--- Top Performer ---\n";
                top->displayData();
                cout << "--- Lowest Performer ---\n";
                low->displayData();
            }
        }

        else if (choice == 5) {
            if (students.empty()) {
                cout << "No student records available.\n";
            } else {
                int gradeCount[5] = {0}; // A, B, C, D, F

                for (const auto& s : students) {
                    if (s.getGrade() == 'A') gradeCount[0]++;
                    else if (s.getGrade() == 'B') gradeCount[1]++;
                    else if (s.getGrade() == 'C') gradeCount[2]++;
                    else if (s.getGrade() == 'D') gradeCount[3]++;
                    else if (s.getGrade() == 'F') gradeCount[4]++;
                }

                cout << "\n--- Grade Distribution ---\n";
                cout << "A: " << gradeCount[0] << "\n";
                cout << "B: " << gradeCount[1] << "\n";
                cout << "C: " << gradeCount[2] << "\n";
                cout << "D: " << gradeCount[3] << "\n";
                cout << "F: " << gradeCount[4] << "\n";
            }
        }

        else if (choice == 6) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
