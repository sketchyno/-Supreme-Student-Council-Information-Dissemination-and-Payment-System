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
        cout << "\t\tPlease press ENTER to proceed...";
        cin.ignore();
        cin.get();
        system("clear");
    }

    void viewAnnouncement() {
        system("clear");
        bool haveAnnouncement = false;
        cout << "\t\t---------------------------" << endl;
        cout << "\t\t       VIEW ANNOUNCEMENTS       " << endl;
        cout << "\t\t---------------------------" << endl;

        for (int i = 0; i < announcementCount; i++) {
            if (!announcements[i].title.empty() && !announcements[i].content.empty()) {
                haveAnnouncement = true;
                cout << "\t\t---------------------------" << endl;
                cout << "\t\tTitle: " << announcements[i].title << endl;
                cout << "\t\tContent: " << announcements[i].content << endl;
                cout << "\t\t---------------------------" << endl;
            }
        }

        if (!haveAnnouncement) {
            cout << "\t\tNo announcements found." << endl;
        }

        pressEnterToContinue();
    }

    void addAnnouncement() {
        string title;
        string content;
        cout << "\t\t\t\t\t------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t"<< endl;
        cout << "\t\t\t\t\t\t           ADD ANNOUNCEMENT"<< endl;
        cout << "\t\t\t\t\t\t\t"<< endl;
        cout << "\t\t\t\t\t------------------------------------------------" << endl;
        do {
            cout << "\t\t\t\t\tEnter Title: ";
            getline(cin, title);
            cout << "\t\t\t\t\tEnter Content: ";
            getline(cin, content);
            cout << endl;

            if (announcementCount < maxAnnounce) {
                announcements[announcementCount].title = title;
                announcements[announcementCount].content = content;
                announcementCount++;
                cout << "\t\t\t\t\t\t~Announcement added successfully!~" << endl;
                
            }
            else {
                cout << "\t\t\t\t\tMaximum number of announcements reached. Cannot add more." << endl;
            }
            cout << endl;
            cout << "\t\t\t\t\tDo you want to add another announcement? (Y/N): ";
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
            cout << "\t\tEnter Title to Update: ";
            getline(cin, search);

            for (int i = 0; i < announcementCount; i++) {
                if (announcements[i].title == search) {
                    cout << "\t\tEnter New Content: ";
                    getline(cin, announcements[i].content);
                    cout << "\t\t~Announcement updated successfully!~" << endl;
                    break;
                }
            }

            cout << "\t\tNo matching announcement found." << endl;
            cout << "\t\tDo you want to update another announcement? (Y/N): ";
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
            cout << "\t\tEnter Title to Delete: ";
            getline(cin, search);

            for (int i = 0; i < announcementCount; i++) {
                if (announcements[i].title == search) {
                    announcements[i].title = "";
                    announcements[i].content = "";
                    cout << "\t\tAnnouncement deleted successfully!" << endl;
                    break;
                }
            }

            cout << "\t\tNo matching announcement found." << endl;
            cout << "\t\tDo you want to delete another announcement? (Y/N): ";
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
            cout << "\t\t\t\t\t----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t           ADMIN          " << endl;
            cout << "\t\t\t\t\t----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t"<< endl;
            cout << "\t\t\t\t\t   [1] \tAdd Announcement" << endl;
            cout << "\t\t\t\t\t   [2] \tUpdate Announcement" << endl;
            cout << "\t\t\t\t\t   [3] \tDelete Announcement" << endl;
            cout << "\t\t\t\t\t   [4] \tView Announcement" << endl; 
            cout << "\t\t\t\t\t   [5] \tSearch Student Information" << endl;
            cout << "\t\t\t\t\t   [6] \tLog Out" << endl;
            cout << "\t\t\t\t\t\t"<< endl;
            cout << "\t\t\t\t\t----------------------------------------" << endl;
            cout << "\t\t\t\t\tEnter your choice: ";
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
                cout << "\t\tInvalid choice. Please try again." << endl;
            }

            system("clear");
        } while (adminChoice != 6);
    }

    void searchStudentInformation() {
        string search;

        do {
            cin.ignore();
            cout << "\t\tEnter SR Code to Search: ";
            getline(cin, search);

            for (int i = 0; i < studentCount; i++) {
                if (students[i].srCode == search) {
                    cout << "\t\tName: " << students[i].name << endl;
                    cout << "\t\tSR Code: " << students[i].srCode << endl;
                    cout << "\t\tProgram: " << students[i].program << endl;
                    cout << "\t\tSection/Block: " << students[i].sectionBlock << endl;
                    if (students[i].isPaid) {
                        cout << "\t\tPayment Status: Paid" << endl;
                    }
                    else {
                        cout << "\t\tPayment Status: Unpaid" << endl;
                    }
                    break;
                }
            }

            cout << "\t\tNo matching student found." << endl;
            cout << "\t\tDo you want to search for another student? (Y/N): ";
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
            cout << "\t\tMaximum number of students reached. Please refer to the admin" << endl;
            pressEnterToContinue();
            return;
        }

        Student newStudent;

        do {
            cin.ignore();
            cout << "\t\t===============================" << endl;
            cout << "\t\t     Register Student    " << endl;
            cout << "\t\t===============================" << endl;
            cout << "\t\tEnter Name: ";
            getline(cin, newStudent.name);
            cout << "\t\tEnter SR Code (Username): ";
            getline(cin, newStudent.srCode);
            cout << "\t\tEnter Program: ";
            getline(cin, newStudent.program);
            cout << "\t\tEnter Section/Block: ";
            getline(cin, newStudent.sectionBlock);
            cout << "\t\tEnter Password: ";
            getline(cin, newStudent.password);

            students[studentCount] = newStudent;
            studentCount++;

            cout << "\t\t===============================" << endl;
            cout << endl;
            cout << "\t\t~~ Student Successfully Registered ~~" << endl;
            cout << "Please Click Enter To Exit" << endl;
            cout << "\t\t===============================" << endl;
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
            cout << "\t\tSSC Fee Payment" << endl;
            cout << "\t\tSSC Fee: PHP 150.00" << endl;
            cout << "\t\tEnter Cash Amount: ";
            cin >> cashAmount;

            if (cashAmount >= 150) {
                double change = cashAmount - 150;
                cout << "\t\tPayment successful! Change: " << change << endl;
                student.isPaid = true;
            }
            else {
                cout << "\t\tInsufficient cash. Payment unsuccessful." << endl;
            }

            cout << "\t\tDo you want to make another payment? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        pressEnterToContinue();
    }

    bool adminLogin() {
       

        string username, password;
        string defaultUsername = "sscadmin";
        string defaultPassword = "test";
        cout << "\t\t\t\t\t\t+---------------------------+" << endl;
        cout << "\t\t\t\t\t\t\t"<< endl;
        cout << "\t\t\t\t\t\t       SSC ADMIN LOGIN"<< endl;
        cout << "\t\t\t\t\t\t\t"<< endl;
        cout << "\t\t\t\t\t\t+---------------------------+" << endl;

        do {
            cout << "\t\t\t\t\t\t\t"<< endl;
            cout << "\t\t\t\t\t\ttEnter Username: ";
            cin >> username;
            cout << "\t\t\t\t\t\tEnter Password: ";
            cin >> password;
            cout << endl;

            if (username == defaultUsername && password == defaultPassword) {
                return true;
            }
            else {
                cout << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
            }
        } while (true);
    }

    bool studentLogin() {
        system("clear");

        string username, password;
        cout << "\t\t=====================" << endl;
        cout << "\t\t   Student Login   " << endl;
        cout << "\t\t=====================" << endl;
        cout << "\t\tEnter Username (SR Code): ";
        cin >> username;
        cout << "\t\tEnter Password: ";
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
            cout << "\t\t===============================" << endl;
            cout << "\t\tStudent Page    " << endl;
            cout << "\t\t===============================" << endl;
            cout << "\t\t1. View Announcements" << endl;
            cout << "\t\t2. SSC Fee Payment" << endl;
            cout << "\t\t3. Log Out" << endl;
            cout << "\t\t===============================" << endl;
            cout << "\t\tEnter your choice: ";
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
                cout << "\t\tInvalid choice. Please try again." << endl;
            }

            system("clear");
        } while (studentChoice != 3);
    }

    void run() {
        int mainChoice;

        do {
            cout << "\t\t\t\t========================================================" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\tSupreme Student Council" << endl;
            cout << "\t\t\t\t\tInformation Dissemination and Payment System" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t========================================================" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t\tBy" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\tMendoza, Janelle P." << endl;
            cout << "\t\t\t\t\t     Pentinio, Mhark Anthony O." << endl;
            cout << "\t\t\t\t\t\tSaludaga, Gilbert L." << endl;
            cout << endl;
            cout << "\t\t\t       "; pressEnterToContinue();
            

            cout << "\t\t\t\t\t\t+++++++++++++++++++++++++++" << endl;
            cout << "\t\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t[1]\tAdmin Login" << endl;
            cout << "\t\t\t\t\t\t[2]\tStudent Login" << endl;
            cout << "\t\t\t\t\t\t[3]\tStudent Register" << endl;
            cout << "\t\t\t\t\t\t[4]\tExit" << endl;
            cout << "\t\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t+++++++++++++++++++++++++++" << endl;
            cout << "\t\t\t\t\t\tEnter a number : ";
            cin >> mainChoice;
            cout << endl;

            switch (mainChoice) {
            case 1:
                if (adminLogin()) {
                    adminPage();
                }
                else {
                    cout << "\t\tAdmin login unsuccessful." << endl;
                    pressEnterToContinue();
                }
                break;
            case 2:
                if (studentLogin()) {
                    studentPage();
                }
                else {
                    cout << "\t\tStudent login unsuccessful." << endl;
                    pressEnterToContinue();
                }
                break;
            case 3:
                studentRegister();
                break;
            case 4:
                cout << "\t\tThank you for using the SSC Information System. Goodbye!" << endl;
                break;
            default:
                cout << "\t\tInvalid choice. Please try again." << endl;
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
