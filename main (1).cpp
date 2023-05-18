#include <iostream>
#include <string>

using namespace std;

const int maxStudcout = 1000;  // Maximum number of students

struct Student {
    string name;
    string srCode;
    string program;
    string sectionBlock;
    string password;
};

void pressEnterToContinue() {
    cout << "Please press ENTER to proceed...";
    cin.ignore();
    cin.get();
    system("cls");
}

void studentRegister(Student* students, int& studentCount) {
    if (studentCount >= maxStudCout) {
        cout << "Maximum number of students reached. Please refer to the admin" << endl;
        pressEnterToContinue();
        return;
    }

    cout << "===============================" << endl;
    cout << "Register Student" << endl;
    cout << "===============================" << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, students[studentCount].name);
    cout << "Enter Sr-Code (Username): ";
    cin >> students[studentCount].srCode;
    cout << "Enter Program: ";
    cin.ignore();
    getline(cin, students[studentCount].program);
    cout << "Enter Section/Block: ";
    getline(cin, students[studentCount].sectionBlock);
    cout << "Enter Password: ";
    cin >> students[studentCount].password;

    cout << "===============================" << endl;
    cout << endl;
    cout << "~~ Student Successfully Registered ~~" << endl;
    cout << "Please Click Enter To Exit" << endl;
    cout << "===============================" << endl;
    pressEnterToContinue();

    studentCount++;
}

bool adminLogin() {
    string username, password;
    string defaultUsername = "sscadmin";
    string defaultPassword = "adminpassword";

    cout << "Admin Login" << endl;
    
    do {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << endl;

        if (username == defaultUsername && password == defaultPassword) {
            return true;
        } else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    } while (true);
}

void adminPage() {
    int adminChoice;

    do {
        cout << "=====================" << endl;
        cout << "ADMIN" << endl;
        cout << "=====================" << endl;
        cout << "1. Add Announcement" << endl;
        cout << "2. Update Announcement" << endl;
        cout << "3. Delete Announcement" << endl;
        cout << "4. Search Student Information" << endl;
        cout << "5. Log Out" << endl;
        cout << "=====================" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;
        cout << endl;

        switch (adminChoice) {
            case 1:
                // addAnnouncement();
                cout << "Add " << endl;
                break;
            case 2:
                // updateAnnouncement();
                cout << "Update " << endl;
                break;
            case 3:
                // deleteAnnouncement();
                cout << "Delete " << endl;
                break;
            case 4:
                // searchStudentInformation();
                cout << "Search" << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("clear"); 
    } while (adminChoice != 5);
}

bool studentLogin(Student* students, int studentCount) {
    string username, password;
    cout << "=====================" << endl;
    cout << "Student Login" << endl;
    cout << "=====================" << endl;
    cout << "Enter Username (SR Code): ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].srCode == username && students[i].password == password) {
            return true;
        }
    }
    return false;
}

void studentPage() {
    int studentChoice;

    do {
        cout << "===============================" << endl;
        cout << "Student Page" << endl;
        cout << "===============================" << endl;
        cout << "1. View Announcements" << endl;
        cout << "2. SSC Fee Payment" << endl;
        cout << "3. Log Out" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";
        cin >> studentChoice;
        cout << endl;

        switch (studentChoice) {
            case 1:
                // viewAnnouncements();
                cout << "View Announcements" << endl;
                break;
            case 2:
                // sscFeePayment();
                cout << "SSC Fee Payment" << endl;
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("clear"); 
    } while (studentChoice != 3);
}

int main() {
    Student students[maxStudcout];
    int studentCount = 0;

    int mainChoice;

    do {
        cout << "================================" << endl;
        cout << "Supreme Student Council" << endl;
        cout << "Information Dissemination and Payment System" << endl;
        cout << "================================" << endl;
        cout << endl;
        cout << "By" << endl;
        cout << endl;
        cout << "Mendoza, Janelle P." << endl;
        cout << "Pentinio, Mhark Anthony O." << endl;
        cout << "Saludaga, Gilbert L." << endl;
        pressEnterToContinue();

        cout << "=====================" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Student Login" << endl;
        cout << "3. Student Register" << endl;
        cout << "4. Exit" << endl;
        cout << "=====================" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;
        cout << endl;

        switch (mainChoice) {
            case 1:
                if (adminLogin()) {
                    adminPage();
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                    pressEnterToContinue();
                }
                break;
            case 2:
                if (studentLogin(students, studentCount)) {
                    studentPage();
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                    pressEnterToContinue();
                }
                break;
            case 3:
                studentRegister(students, studentCount);
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("clear");
    } while (mainChoice != 4);

    return 0;
}
