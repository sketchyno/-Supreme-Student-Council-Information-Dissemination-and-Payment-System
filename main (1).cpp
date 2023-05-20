#include <iostream>
#include <string>

using namespace std;

const int maxStudCount = 1000;
const int maxAnnounce = 100;

class Student {
public:
    string name;
    string srCode;
    string program;
    string sectionBlock;
    string password;
    bool isPaid;

    Student() {
        isPaid = false;
    }
};

class Announcement {
public:
    string title;
    string content;
};

class SSCSystem {
private:
    Student students[maxStudCount];
    int studentCount;
    Announcement announcements[maxAnnounce];
    int announcementCount;
    int currentStudentIndex;

public:
    SSCSystem() {
        studentCount = 0;
        announcementCount = 0;
    }

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
        cout << "       VIEW ANNOUNCEMENTS       " << endl;
        cout << "---------------------------" << endl;

        for (int i = 0; i < announcementCount; i++) {
            if (!announcements[i].title.empty() && !announcements[i].content.empty()) {
                haveAnnouncement = true;
                cout << "---------------------------" << endl;
                cout << "Title: " << announcements[i].title << endl;
                cout << "Content: " << announcements[i].content << endl;
                cout << "---------------------------" << endl;
            }
        }

        if (!haveAnnouncement) {
            cout << "No announcements found." << endl;
        }

        pressEnterToContinue();
    }

    void addAnnouncement() {
        string title;
        string content;

        do {
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Content: ";
            getline(cin, content);

            if (announcementCount < maxAnnounce) {
                announcements[announcementCount].title = title;
                announcements[announcementCount].content = content;
                announcementCount++;
                cout << "Announcement added successfully!" << endl;
            } else {
                cout << "Maximum number of announcements reached. Cannot add more." << endl;
            }

            cout << "Do you want to add another announcement? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
    }

    void updateAnnouncement() {
        string search;

        do {
            cin.ignore();
            cout << "Enter Title to Update: ";
            getline(cin, search);

            for (int i = 0; i < announcementCount; i++) {
                if (announcements[i].title == search) {
                    cout << "Enter New Content: ";
                    getline(cin, announcements[i].content);
                    cout << "Announcement updated successfully!" << endl;
                    break;
                }
            }

            cout << "No matching announcement found." << endl;
            cout << "Do you want to update another announcement? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
    }

    void deleteAnnouncement() {
        string search;

        do {
            cin.ignore();
            cout << "Enter Title to Delete: ";
            getline(cin, search);

            for (int i = 0; i < announcementCount; i++) {
                if (announcements[i].title == search) {
                    announcements[i].title = "";
                    announcements[i].content = "";
                    cout << "Announcement deleted successfully!" << endl;
                    break;
                }
            }

            cout << "No matching announcement found." << endl;
            cout << "Do you want to delete another announcement? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
    }

    void adminPage() {
        system("clear");

        int adminChoice;

        do {
            cout << "=====================" << endl;
            cout << "          ADMIN          " << endl;
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
                    updateAnnouncement();
                    break;
                case 3:
                    deleteAnnouncement();
                    break;
                case 4:
                    viewAnnouncement();
                    break;
                case 5:
                    searchStudentInformation();
                    break;
                case 6:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            system("clear");
        } while (adminChoice != 6);
    }

    void searchStudentInformation() {
        string search;

        do {
            cin.ignore();
            cout << "Enter SR Code to Search: ";
            getline(cin, search);

            for (int i = 0; i < studentCount; i++) {
                if (students[i].srCode == search) {
                    cout << "Name: " << students[i].name << endl;
                    cout << "SR Code: " << students[i].srCode << endl;
                    cout << "Program: " << students[i].program << endl;
                    cout << "Section/Block: " << students[i].sectionBlock << endl;
                    if (students[i].isPaid) {
                        cout << "Payment Status: Paid" << endl;
                    } else {
                        cout << "Payment Status: Unpaid" << endl;
                    }
                    break;
                }
            }

            cout << "No matching student found." << endl;
            cout << "Do you want to search for another student? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
    }

    void studentRegister() {
        system("clear");

        if (studentCount >= maxStudCount) {
            cout << "Maximum number of students reached. Please refer to the admin" << endl;
            pressEnterToContinue();
            return;
        }

        Student newStudent;

        do {
            cin.ignore();
            cout << "===============================" << endl;
            cout << "     Register Student    " << endl;
            cout << "===============================" << endl;
            cout << "Enter Name: ";
            getline(cin, newStudent.name);
            cout << "Enter SR Code (Username): ";
            getline(cin, newStudent.srCode);
            cout << "Enter Program: ";
            getline(cin, newStudent.program);
            cout << "Enter Section/Block: ";
            getline(cin, newStudent.sectionBlock);
            cout << "Enter Password: ";
            getline(cin, newStudent.password);

            students[studentCount] = newStudent;
            studentCount++;

            cout << "===============================" << endl;
            cout << endl;
            cout << "~~ Student Successfully Registered ~~" << endl;
            cout << "Please Click Enter To Exit" << endl;
            cout << "===============================" << endl;
            cout << "Do you want to register another student? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
    }

    void payFee(Student& student) {
        double cashAmount;

        do {
            cout << "SSC Fee Payment" << endl;
            cout << "SSC Fee: PHP 150.00" << endl;
            cout << "Enter Cash Amount: ";
            cin >> cashAmount;

            if (cashAmount >= 150) {
                double change = cashAmount - 150;
                cout << "Payment successful! Change: " << change << endl;
                student.isPaid = true;
            } else {
                cout << "Insufficient cash. Payment unsuccessful." << endl;
            }

            cout << "Do you want to make another payment? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
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
            } else {
                cout << "Invalid username or password. Please try again." << endl;
            }
        } while (true);
    }

    bool studentLogin() {
        system("clear");

        string username, password;
        cout << "=====================" << endl;
        cout << "   Student Login   " << endl;
        cout << "=====================" << endl;
        cout << "Enter Username (SR Code): ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].srCode == username && students[i].password == password) {
                currentStudentIndex = i;
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
            cout << "     Student Page    " << endl;
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
                    payFee(students[currentStudentIndex]);
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            system("clear");
        } while (studentChoice != 3);
    }

    void run() {
        int mainChoice;

        do {
            cout << "===============================" << endl;
            cout << "         Welcome to SSC        " << endl;
            cout << "===============================" << endl;
            cout << "1. Admin Login" << endl;
            cout << "2. Student Login" << endl;
            cout << "3. Register Student" << endl;
            cout << "4. Exit" << endl;
            cout << "===============================" << endl;
            cout << "Enter your choice: ";
            cin >> mainChoice;
            cout << endl;

            switch (mainChoice) {
                case 1:
                    if (adminLogin()) {
                        adminPage();
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
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            system("clear");
        } while (mainChoice != 4);
    }
};

int main() {
    SSCSystem ssc;
    ssc.run();
    return 0;
}
