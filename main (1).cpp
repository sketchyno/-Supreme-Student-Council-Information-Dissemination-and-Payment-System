#include <iostream>
#include <string>


void adminPage();
void   exitFunc();

using namespace std;

const int maxStudcout = 1000;  // Maximum number of students
const int maxAnnounce = 100;   // Maximum Announcement 

string TitleAdd[maxAnnounce] = {};
string ContentAdd[maxAnnounce] = {};

void addAnnouncement() {

    string title;
    string content;

    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Content: ";
    getline(cin, content);

    for (int i = 0; i < maxAnnounce; i++)
    {
        if (TitleAdd[i] == "\0")
        {
            TitleAdd[i] = title;
            ContentAdd[i] = content;

            break;
        }
    }
    exitFunc();


}

void updateAnnouncement(string search) {


    system("clear");

    string title;
    string content;
    int update = 0;

    for (int i = 0; i < maxAnnounce; i++)
    {
        if (TitleAdd[i] == search)
        {
            update++;

            cout << "Title content: ";
            getline(cin, content);

            ContentAdd[i] = content;

            cout << "Content Successfully Updated" << endl;
            break;
        }
        if (update == 0)
        {
            cout << "No Match Found" << endl;
        }
    }

}

void deleteAnnouncement(string search) {

    system("clear");
    int deleteAnn = 0;

    for (int i = 0; i < maxAnnounce; i++)
    {
        if (TitleAdd[i] == search)
        {

            deleteAnn++;

            TitleAdd[i] = "";
            ContentAdd[i] = "";

            cout << "Announcement Successfully Deleted" << endl;
        }
        if (deleteAnn == 0)
        {
            cout << "No Match Found" << endl;
        }
    }
    exitFunc();
}

void exitFunc() {
    string adminChoice;
    cout << "Enter (E/e) to exit: ";
    cin >> adminChoice;

    if (adminChoice == "e" && adminChoice == "E") {
        adminPage();
    }
    else {
        return;

    }
}
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
    system("clear");
}
void viewAnnouncement() {
    system("clear");
    bool haveAnnouncement = false;
    cout << "---------------------------" << endl;
    cout << "     VIEW ANNOUNCEMENTS    " << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < maxAnnounce; i++) {
        if (TitleAdd[i] != "" && ContentAdd[i] != "")
        {
            haveAnnouncement = true;
            cout << "---------------------------" << endl;
            cout << "Title: " << ContentAdd[i] << endl;

            cout << "Content: " << ContentAdd[i] << endl;

            cout << "---------------------------" << endl;
        }
    }

    if (!haveAnnouncement) {
        cout << "No announcements found." << endl;
    }
    exitFunc();



};
void studentRegister(Student* students, int& studentCount) {

    system("clear");

    if (studentCount >= maxStudcout) {
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

    system("clear");

    string username, password;
    string defaultUsername = "sscadmin";
    string defaultPassword = "test";

    cout << "Admin Login" << endl;

    do {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << endl;

        if (username == defaultUsername && password == defaultPassword) {
            return true;
        }
        else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    } while (true);

}

void searchStudentInformation() {

};
void adminPage() {

    system("clear");
    string announceAdmin;

    int adminChoice;

    do {
        cout << "=====================" << endl;
        cout << "ADMIN" << endl;
        cout << "=====================" << endl;
        cout << "1. Add Announcement" << endl;
        cout << "2. Update Announcement" << endl;
        cout << "3. Delete Announcement" << endl;
        cout << "4. View Announcement" << endl;
        cout << "5. Search Student Information" << endl;
        cout << "6. Log Out" << endl;
        cout << "=====================" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;
        cout << endl;
        cin.ignore();

        switch (adminChoice) {
        case 1:

            addAnnouncement();
            break;
        case 2:

            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, announceAdmin);
            updateAnnouncement(announceAdmin);
            break;
        case 3:

            cin.ignore();
            cout << "Enter Title to Delete: ";
            getline(cin, announceAdmin);
            deleteAnnouncement(announceAdmin);
            break;
        case 4:
            viewAnnouncement();
            break;
        case 5:
            searchStudentInformation();
            break;

        case 6:
            return;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("clear");
    } while (adminChoice != 5);
}

bool studentLogin(Student* students, int studentCount) {

    system("clear");

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

    system("clear");

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

            viewAnnouncement();
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
            }
            else {
                cout << "Invalid username or password. Please try again." << endl;
                pressEnterToContinue();
            }
            break;
        case 2:
            if (studentLogin(students, studentCount)) {
                studentPage();
            }
            else {
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
            system("clear");
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("clear");
    } while (mainChoice != 4);

    return 0;
}
