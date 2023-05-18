#include <iostream>
#include <string>


using namespace std;

void pressEnterToContinue() {
    cout << "Please press ENTER to proceed...";
    cin.ignore();
    cin.get();
    system("cls"); 
}
//Function used for admin page
bool adminLogin() {
    string username, password;
    string defaultUSer= "sscadmin";
    string defaultPass= "adminpassword":
    cout << "Admin Login" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    if (defaultUser!=username && defaultPass !=password){
       
    }
    else {
        return true;
    }

}

void addAnnouncement(){
//lagay logi dito
}

void updateAnnouncement(){
//lagay logi dito
}

void deleteAnnouncement(){
//lagay logi dito
}

void searchStudentInformation(){
//lagay logi dito
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
                searchStudentInformation();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        system("clear"); 
    } while (adminChoice != 5);
}

//Function Used for Student Page
bool studentLogin() {
    string username, password;
    cout << "=====================" << endl;
    cout << "Student Login" << endl;
    cout << "=====================" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    return true; 
}


void viewAnnouncements() {
    cout << "View Announcements" << endl;
    // lagay logic
    pressEnterToContinue();
}

void sscFeePayment() {
    cout << "SSC Fee Payment" << endl;
    // lagay logic
    pressEnterToContinue();
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

        switch (studentChoice) {
            case 1:
                viewAnnouncements();
                break;
            case 2:
                sscFeePayment();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        system("clear"); 
    } while (studentChoice != 3);
}

void studentRegister() {
    string name, srCode, program, sectionBlock, password;
    cout << "===============================" << endl;
    cout << "Register Student" << endl;
    cout << "===============================" << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Sr-Code: ";
    cin >> srCode;
    cout << "Enter Program: ";
    cin.ignore();
    getline(cin, program);
    cout << "Enter Section/Block: ";
    getline(cin, sectionBlock);
    cout << "Enter Password: ";
    cin >> password;
    cout << "===============================" << endl;
    cout << endl;
    cout << "~~ Student Successfully Registered ~~" << endl;
    cout << "Please Click Enter To Exit" << endl;
    cout << "===============================" << endl;
    pressEnterToContinue();
}


//Main FUnction 
int main() {
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

    int mainChoice;

    do {
        cout << "=====================" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Student Login" << endl;
        cout << "3. Student Register" << endl;
        cout << "4. Exit" << endl;
        cout << "=====================" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:

                if (adminLogin(true)) {
                    adminPage();
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                   adminLogin();
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
        system("clear");
    } while (mainChoice != 4);

    return 0;
}
