#include <iostream>
#include "linkedlist.h"

using namespace std;

Guest getGuestInfo();

int main(){
    List<Guest> party_list; // need to fix
    // Data<Guest> temp_data_guest; // need to fix
    Guest temp_guest;
    int menuChoice;
    int list_location_choice;

    cout << "\nWelcome to the Diddy Party!" << endl;

    cout << "\nEnter information for first guest" << endl;
    temp_guest = getGuestInfo();
    
    cout << "before append";
    party_list.appendNode(temp_guest); // can also load info from file
    cout << "after append";

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
                cout << "Invalid input!" << endl;
                break;

            case 1: // ADD TO LIST
                list_location_choice = 0;
                do{
                    cout << endl;
                    cout << "1. Add guest to front of list" << endl;
                    cout << "2. Add guest to back of list" << endl;
                    cout << "Enter choice: ";
                    cin >> list_location_choice;
                }while(list_location_choice != 1 || list_location_choice != 2);

                temp_guest = getGuestInfo();
                // temp_data_guest.setValue(temp_guest);
                
                if(list_location_choice == 1){ // Add guest to front of list
                    party_list.pushNode(temp_guest);
                    cout << endl << temp_guest.getName() << " has been added to front of list!" << endl;
                }
                else{ // Add guest to back of list
                    party_list.appendNode(temp_guest);
                    cout << endl << temp_guest.getName() << " has been added to back of list!" << endl;
                }
                
                break;

            case 2:
                list_location_choice = 0;
                do{
                    cout << endl;
                    cout << "1. Remove guest from front of list" << endl;
                    cout << "2. Remove guest from back of list" << endl;
                    cout << "Enter choice: ";
                    cin >> list_location_choice;
                }while(list_location_choice != 1 || list_location_choice != 2);

                if(list_location_choice == 1){ // Remove guest from front of list
                     // pop back
                    cout << endl /*<< guest name */ << " has been deleted from front of list!" << endl;
                }
                else{ // Remove guest from back of list
                    // pop back
                    cout << endl /*<< guest name*/ << " has been deleted from back of list!" << endl;
                }
                

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
    Guest g;
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

    g = Guest(name, age, times_attended, floz_bb_oil_used);
    return g;
}