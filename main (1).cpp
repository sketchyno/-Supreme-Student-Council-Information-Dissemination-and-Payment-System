#include <iostream>
#include <string>

using namespace std;

const int maxStudCount = 100;
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
    int currentStudentIndex;
    Student students[maxStudCount];
    int studentCount;
    Announcement announcements[maxAnnounce];
    int announcementCount;
    

public:
    

    SSCSystem() : currentStudentIndex(0) {
        studentCount = 0;
        announcementCount = 0;

    }
    void studentRegister() {


        if (studentCount >= maxStudCount) {
            cout << "\t\tMaximum number of students reached. Please refer to the admin" << endl;
            pressEnterToContinue();
            return;
        }

        Student newStudent;

        do {
            cin.ignore();
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t     Register Student    " << endl;
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << "\t\t\tEnter Name: ";
            getline(cin, newStudent.name);
            cout << "\t\t\tEnter SR Code (Username): ";
            getline(cin, newStudent.srCode);
            cout << "\t\t\tEnter Program: ";
            getline(cin, newStudent.program);
            cout << "\t\t\tEnter Section/Block: ";
            getline(cin, newStudent.sectionBlock);
            cout << "\t\t\tEnter Password: ";
            getline(cin, newStudent.password);
            
            this->students[studentCount] = newStudent;
            studentCount++;

            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << endl;
            cout << "\t\t\t\t\t    ~ Student Successfully Registered ~" << endl;
            cout << "\t\t\t\t\t       Please Click Enter To Exit" << endl;
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << "\t\t\t    Do you want to register another student? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

    }

    void pressEnterToContinue() {
        cout << "\t\tPlease press ENTER to proceed...";
        cin.ignore();
        cin.get();

    }

    void pressEnterToExit() {
        cout << "\t\tPlease press ENTER to exit..";
        cin.ignore();
        cin.get();
    }

    void viewAnnouncement() {

        bool haveAnnouncement = false;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t     VIEW ANNOUNCEMENTS    " << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;

        for (int i = 0; i < maxAnnounce; i++) {
            if (announcements[i].title != "" && announcements[i].content != "")
            {
                haveAnnouncement = true;
                cout << "\t\t\t-----------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t" << endl;
                cout << "\t\t\tTitle: " << announcements[i].title << endl;
                cout << endl;

                cout << "\t\t\tContent: " << announcements[i].content << endl;
                cout << endl;
                cout << "\t\t\t\t\t\t\t" << endl;
                cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            }

        }

        pressEnterToExit();

    }
    void addAnnouncement() {
        string title;
        string content;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t    ADD ANNOUNCEMENT" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\tPress ENTER to proceed adding announcement...  ";
        do {

            cin.ignore();
            cout << "\t\t\tEnter Title: ";
            getline(cin, title);
            cout << "\t\t\tEnter Content: ";
            getline(cin, content);
            cout << "\t\t\t\t\t\t\t" << endl;

            if (announcementCount < maxAnnounce) {
                announcements[announcementCount].title = title;
                announcements[announcementCount].content = content;
                announcementCount++;
                cout << "\t\t\t\t\t ~ Announcement added successfully! ~" << endl;
            }
            else {
                cout << "\t\t\t\t   Maximum number of announcements reached. Cannot add more." << endl;
            }
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;

            cout << "\t\t\t\t    Do you want to add another announcement? (Y/N): ";
            char choice;
            cin >> choice;
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t " << endl;
            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        return;

    }


    void deleteAnnouncement() {
        string search;

        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t    DELETE ANNOUNCEMENT" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\tPress ENTER to proceed deleting...  ";

        do {
            cin.ignore();
            cout << "\t\t\tEnter Title to Delete: ";
            getline(cin, search);
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;

            bool found = false;  

            for (int i = 0; i < announcementCount; i++) {
                if (announcements[i].title == search) {
                    announcements[i].title = "";
                    announcements[i].content = "";
                    cout << "\t\t\t\t\t ~ Announcement deleted successfully! ~" << endl;
                    found = true;  
                    break;
                }
            }

            if (!found) {
                cout << "\t\t\t\t\t            No matching found." << endl;
            }

            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t    Do you want to delete another announcement? (Y/N): ";
            char choice;
            cin >> choice;
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        return;
    }


    void updateAnnouncement() {
        string search;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t    UPDATE ANNOUNCEMENT" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\tPress ENTER to proceed updating content...  ";

        do {
            cin.ignore();
            cout << "\t\t\tEnter Title to Update: ";
            getline(cin, search);
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;

            bool found = false;  

            for (int i = 0; i < announcementCount; i++) {
                if (announcements[i].title == search) {
                    cout << "\t\t\tEnter New Content: ";
                    getline(cin, announcements[i].content);
                    cout << "\t\t\t\t\t\t\t" << endl;
                    cout << "\t\t\t\t\t ~ Announcement updated successfully! ~" << endl;
                    found = true;  
                    break;
                }
            }

            if (!found) {
                cout << "\t\t\t\t\t            No matching found." << endl;
            }

            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t    Do you want to update another content? (Y/N): ";
            char choice;
            cin >> choice;
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        return;
    }

    void monitorFeePayment() {
        int numPaid = 0;
        cout << "\t\t\t\t    -------------------------------------------------" << endl;
        cout << "\t\t\t\t\t             SSC FEE MONITORING          " << endl;
        cout << "\t\t\t\t    -------------------------------------------------" << endl;

        cout << "\t\t\t\t      Number of students who have paid: " << numPaid << endl;
        cout << "\t\t\t\t      Total number of students: " << studentCount << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t    =================================================" << endl;

        cout << "\t\t\t\t    List of students who have not paid their fees:" << endl;

        for (int i = 0; i < studentCount; i++) {
            const Student& student = students[i];
            if (!student.isPaid) {
                cout << "\t\t " << student.name << "-\t\t\t\t    " << student.srCode << endl;
            }
            else {
                numPaid++;
            }
        }

        cout << "\t\t\t\t    =================================================" << endl;


        cout << "\t\t\t\t";     pressEnterToExit();
    }


    void adminPage() {
        system("clear");
        string announceAdmin;

        int adminChoice;

        do {
            cout << "\t\t\t\t      -------------------------------------------" << endl;
            cout << "\t\t\t\t\t                 ADMIN          " << endl;
            cout << "\t\t\t\t      -------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t         [1] \tAdd Announcement" << endl;
            cout << "\t\t\t\t         [2] \tUpdate Announcement" << endl;
            cout << "\t\t\t\t         [3] \tDelete Announcement" << endl;
            cout << "\t\t\t\t         [4] \tView Announcement" << endl;
            cout << "\t\t\t\t         [5] \tSearch Student Information" << endl;
            cout << "\t\t\t\t         [6] \tSSC Fee Monitoring" << endl;
            cout << "\t\t\t\t         [7] \tLog Out" << endl;
            cout << "\t\t\t\t\t" << endl;

            cout << "\t\t\t\t      -------------------------------------------" << endl;
            cout << "\t\t\t\t      Enter your choice: ";
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
                monitorFeePayment();
                break;
            case 7:
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

            system("clear");
        } while (adminChoice != 7);
    }
    void searchStudentInformation() {
        string search;

        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t    SEARCH STUDENT INFORMATION" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\tPress ENTER to proceed searching content...  ";

        bool found = false;

        do {
            cin.ignore();
            cout << "\t\t\tEnter SR Code to Search: ";
            getline(cin, search);

            for (int i = 0; i < studentCount; i++) {
                if (students[i].srCode == search) {
                    cout << "\t\t\tName: " << students[i].name << endl;
                    cout << "\t\t\tSR Code: " << students[i].srCode << endl;
                    cout << "\t\t\tProgram: " << students[i].program << endl;
                    cout << "\t\t\tSection/Block: " << students[i].sectionBlock << endl;
                    
                    if (students[i].isPaid) {
                        cout << "\t\t\t\t\t\t\t" << endl;
                        cout << "\t\t\tPayment Status: Paid" << endl;
                    }
                    else {
                        cout << "\t\t\tPayment Status: Unpaid" << endl;
                    }
                    found = true;
                    break;
                }
            }


            

            cout << "\t\t\t-----------------------------------------------------------------------" << endl;
            
            if (found == false) {
                cout << "\t\t\t\t\t            No matching found." << endl;
            }
            cout << "\t\t\t\t    Do you want to search another student? (Y/N): ";
            char choice;
            cin >> choice;
            cout << "\t\t\t-----------------------------------------------------------------------" << endl;

            if (choice != 'Y' && choice != 'y')
                break;

        } while (true);

        return;
    }
    

    void payFee(Student& student) {
        double cashAmount;

        do {
            cout << "\t\t\t\t      -----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t                SSC Fee Payment" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t      -----------------------------------------------" << endl;
            cout << "\t\t\t\t                 SSC Fee: PHP 60.00" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t      Enter Cash Amount or enter [1] to exit: ";
            cin >> cashAmount;

            if (cashAmount == 1) {
                break;
            }

            if (cashAmount >= 60) {
                double change;
                change = cashAmount - 60;
                cout << "\t\t\t\t      -----------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t" << endl;
                cout << "\t\t\t\t       Student:        " << students[studentCount].name << endl;
                cout << "\t\t\t\t       Fee Paid:        PHP " << cashAmount << endl;
                cout << "\t\t\t\t       Change:         " << change << endl;
                cout << "\t\t\t\t\t\t" << endl;
                cout << "\t\t\t\t                ~ Payment successful! ~" << endl;
                student.isPaid = true;
                cout << "\t\t\t\t      -----------------------------------------------" << endl;
            }
            else {
                cout << "\t\tInsufficient cash. Payment unsuccessful." << endl;
            }

           
        } while (true);

        if (student.isPaid == true) {
            cout << "\t\t\t\t      -----------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t                 PAYMENT STATUS: PAID" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t      -----------------------------------------------" << endl;
            pressEnterToExit();
            return;
        }
    }

    bool adminLogin() {
        string username, password;
        string defaultUsername = "sscadmin";
        string defaultPassword = "test";
        cout << "\t\t\t\t+-------------------------------------------------------+" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t     SSC ADMIN LOGIN" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t+-------------------------------------------------------+" << endl;

        while (true) {
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\tEnter Username (Enter '1' to exit): ";
            cin >> username;
            if (username == "1") {
                return false;
            }
            cout << "\t\t\t\tEnter Password: ";
            cin >> password;
            cout << endl;



            if (username == defaultUsername && password == defaultPassword) {
                return true;
            }
            else {
                cout << "\t\t\t\t  ~ Invalid username or password. Please try again. ~" << endl;
                cout << "\t\t\t\t\t\t\t" << endl;
            }
            cout << "\t\t\t\t+-------------------------------------------------------+" << endl;



        }

        return false;
    }
    bool studentLogin() {
        string username, password;
        bool isCorrect = false;
        cout << "\t\t\t\t+-----------------------------------------------------------------+" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t              STUDENT LOGIN" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t+-----------------------------------------------------------------+" << endl;
        cout << "\t\t\t\t\t\t\t" << endl;

        while (!isCorrect) {

            cout << "\t\t\t\tEnter username(SR-CODE) or enter '1' to exit: ";
            cin >> username;
            if (username == "1") {
                return false;
            }
            cout << "\t\t\t\tEnter Password: ";
            cin >> password;
            cout << endl;


            for (int i = 0; i < studentCount; i++) {
                if (students[i].srCode == username && students[i].password == password) {
                    currentStudentIndex = i;
                    isCorrect;
                    return true;
                }
            }

            if (!isCorrect) {
                cout << "\t\t\t\t\tInvalid username or password. Please try again." << endl;
            }
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t+-----------------------------------------------------------------+" << endl;
        }

        return true;
    }
    void studentPage() {


        int studentChoice;

        do {
            cout << "\t\t\t\t      -------------------------------------------" << endl;
            cout << "\t\t\t\t\t                 Student Page    " << endl;
            cout << "\t\t\t\t      -------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t         [1] \tView Announcements" << endl;
            cout << "\t\t\t\t         [2] \tSSC Fee Payment" << endl;
            cout << "\t\t\t\t         [3] \tLog Out" << endl;
            cout << "\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t      -------------------------------------------" << endl;
            cout << "\t\t\t\t      Enter the number of your choice: ";
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


        } while (studentChoice != 3);
    }

    void run() {
        int mainChoice;

        do {
            cout << "\t\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t========================================================" << endl;
            cout << "\t\t\t\t========================================================" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\tSupreme Student Council" << endl;
            cout << "\t\t\t\t\tInformation Dissemination and Payment System" << endl;
            cout << "\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t========================================================" << endl;
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
                    cout << "\t\t\t\t\t\t\t\t" << endl;
                    cout << "\t\t\t\t               ~ Admin login unsuccessful ~" << endl;
                    cout << "\t\t\t\t\t\t\t\t" << endl;
                    cout << "\t\t\t\t    "; pressEnterToExit();
                }
                break;
            case 2:
                if (studentLogin()) {
                    studentPage();
                }
                else {
                    cout << "\t\t\t\t\t\t\t\t" << endl;
                    cout << "\t\t\t\t             ~ Student login unsuccessful ~" << endl;
                    cout << "\t\t\t\t\t\t\t\t" << endl;
                    cout << "\t\t\t\t     "; pressEnterToExit();
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
        } while (mainChoice != 4);
    }
};

int main() {
    SSCSystem ssc;
    ssc.run();
    return 0;
}
