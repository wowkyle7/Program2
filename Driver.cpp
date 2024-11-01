#include <iostream>
#include "linkedlist.h"
using namespace std;

Guest getGuestInfo();

int main(){
    List<Guest> party_list; // need to fix
    Data<Guest> temp_data_guest; // need to fix
    Guest temp_guest;
    int menuChoice;
    int list_location_choice;

    cout << "\nWelcome to the Diddy Party!" << endl;

    cout << "\nEnter information for first guest" << endl;
    party_list.appendNode(getGuestInfo()); // can also load info from file

    do{
        // print menu
        cout << endl << endl << string(20, '*') << " MENU " << string(20, '*') << endl;
        cout << "1. Add guest to list" << endl;
        cout << "2. Remove a guest from list" << endl;
        cout << "3. Show all guests" << endl;
        cout << "4. Sort guest list" << endl;
        cout << "5. Exit Program" << endl;

        cout << "\nEnter Choice: ";
        cin >> menuChoice;

        switch(menuChoice){
            default: 
                cout << "Invalid input!";
                break;

            case 1: // push to top
                list_location_choice = 0;
                do{
                    cout << "1. Add guest to front of list" << endl;
                    cout << "2. Add guest to back of list" << endl;
                    cout << "Enter choice: ";
                    cin >> list_location_choice;
                }while(list_location_choice != 1 || list_location_choice != 2);

                temp_guest = getGuestInfo();
                temp_data_guest.setValue(temp_guest);
                
                if(list_location_choice == 1){
                    party_list.pushNode(temp_data_guest);
                    cout << endl << temp_guest.getName() << " has been added to front of list!";
                }
                else{
                    party_list.appendNode(temp_data_guest);
                    cout << endl << temp_guest.getName() << " has been added to back of list!";
                }
                
                break;

            case 2:
                /*
                WILL EITHER GIVE OPTION TO POP FRONT / BACK
                OR
                WILL PROMPT USER FOR POSITION IN LIST TO DELETE NODE
                */
                break;

            case 3:
                /*
                DISPLAY ALL VALUES IN LIST
                */
                break;

            case 4:
                /*
                PROMPT USER HOW THEY WANT TO SORT GUEST LIST (name, age, times attended, bb oil used)
                */
                break;
        }
    }while(menuChoice != 5); // change later
    
    cin.clear();
    return 0;
}

Guest getGuestInfo(){
    string name;
    int age;
    int times_attended;
    float floz_bb_oil_used;

    cout << "\nEnter guest name: ";
    getline(cin >> ws, name);
    cout << "\nEnter guest age: ";
    cin >> age;
    cout << "\nEnter number of times guest has attended: ";
    cin >> times_attended;
    cout << "\nEnter amount of baby oil guest has used (fluid oz): ";
    cin >> floz_bb_oil_used;

    return Guest(name, age, times_attended, floz_bb_oil_used);
}