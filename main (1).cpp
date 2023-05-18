#include <iostream>
#include <string>


using namespace std;

#include <iostream>
#include <string>

using namespace std;

void pressEnterToContinue() {
    cout << "Please press ENTER to proceed...";
    cin.ignore();
    cin.get();
    system("cls");
}
void studentRegister() {
    string name, srCode, program, sectionBlock, password;

    cout << "Register Student" << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Sr-Code: ";
    getline(cin, srCode);
    cout << "Enter Program: ";
    getline(cin, program);
    cout << "Enter Section/Block: ";
    getline(cin, sectionBlock);
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;

    cout << "~~ Student Successfully Registered ~~" << endl;
    cout << "Please Click Enter To Exit" << endl;
    pressEnterToContinue();
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
                cout << "Add Announcement" << endl;
                break;
            case 2:
                // updateAnnouncement();
                cout << "Update Announcement" << endl;
                break;
            case 3:
                // deleteAnnouncement();
                cout << "Delete Announcement" << endl;
                break;
            case 4:
                // searchStudentInformation();
                cout << "Search Student Information" << endl;
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


bool studentLogin() {
    string username, password;
    string studentUsername = "student";
    string studentPassword = "password";

    cout << "Student Login" << endl;

    do {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << endl;

        if (username == studentUsername && password == studentPassword) {
            return true;
        } else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    } while (true);
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
                if (studentLogin()) {
                    studentPage();
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                    pressEnterToContinue();
                }
                break;
            case 3:
                studentRegister();
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
