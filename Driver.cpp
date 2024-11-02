/*
    Author:     Kyle Schultz
    Purpose:    Driver file
*/

#include <iostream>
#include "linkedlist.h"

using namespace std;

Guest getGuestInfo();

int main(){
    List<Guest> party_list;
    Guest temp_guest;
    int menuChoice;
    int list_location_choice;
    int get_from_list_choice;

    cout << fixed << setprecision(1);
    cout << "\nWelcome to the Diddy Party!" << endl;

    do {
        // print menu
        cout << endl << endl << string(20, '*') << " MENU " << string(20, '*') << endl;
        cout << "1. Add guest to list" << endl;
        cout << "2. Remove a guest from list" << endl;
        cout << "3. Display guest(s)" << endl;
        cout << "4. Sort guest list alphabetically" << endl;
        cout << "5. Exit Program" << endl;

        cout << "\nEnter Choice: ";
        cin >> menuChoice;

        switch(menuChoice){
            default: 
                cout << "Invalid input!" << endl;
                break;

            case 1: // ADD TO LIST
                list_location_choice = 0;
                // Checks if the list is empty, since it's redundant to prompt user for choice to add from front or back of list if it's empty
                if(party_list.isEmpty())
                    list_location_choice = 1;
                else{
                    do{
                        cout << endl;
                        cout << "1. Add guest to front of list" << endl;
                        cout << "2. Add guest to back of list" << endl;
                        cout << "Enter choice: ";
                        cin >> list_location_choice;
                        cout << "Choice input: " << list_location_choice << endl;
                    }while(list_location_choice < 1 || list_location_choice > 2);
                }

                temp_guest = getGuestInfo();
                
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

                // Checks if list is empty
                if(party_list.isEmpty()){
                    cout << "There is nothing to remove, the list is empty." << endl;
                    break;
                }

                // Checks if there's only one node in list, since it's redundant to prompt user for choice to remove from front or back of list with only one item
                if(party_list.isOneNode()) 
                    list_location_choice = 1;
                else{
                    do{
                        cout << endl;
                        cout << "1. Remove guest from front of list" << endl;
                        cout << "2. Remove guest from back of list" << endl;
                        cout << "Enter choice: ";
                        cin >> list_location_choice;
                    }while(list_location_choice < 1 || list_location_choice > 2);
                }

                if(list_location_choice == 1){ // Remove guest from front of list
                    temp_guest = party_list.getHeadNode();
                    party_list.popNode();
                    cout << endl << temp_guest.getName() << " has been deleted from front of list!" << endl;
                }
                else{ // Remove guest from back of list
                    temp_guest = party_list.getTailNode();
                    party_list.popBack();
                    cout << endl << temp_guest.getName() << " has been deleted from back of list!" << endl;
                }
                
                break;

            case 3:
                // Displays specified or all nodes in list
                get_from_list_choice = 0;

                do{
                    cout << endl;
                    cout << "1. Get from front of list" << endl;
                    cout << "2. Get from back of list" << endl;
                    cout << "3. Display all items in list" << endl;
                    cout << "Enter choice: ";
                    cin >> get_from_list_choice;
                    cout << "Choice input: " << get_from_list_choice << endl;
                }while(get_from_list_choice < 1 || get_from_list_choice > 3);

                switch(get_from_list_choice){
                    case 1:
                        temp_guest = party_list.getHeadNode();
                        cout << "\n\nGUEST AT HEAD NODE" << endl;
                        cout << left << setw(26) << "    Name: " << temp_guest.getName() << endl;
                        cout << left << setw(26) << "    Age: " << temp_guest.getAge() << endl;
                        cout << left << setw(26) << "    Times Attended: " << temp_guest.getTimesAttended() << endl;
                        cout << left << setw(10) << "    Fl. Oz Baby Oil Used: " << temp_guest.getBbOilUsed() << endl;
                        break;
                    case 2:
                        temp_guest = party_list.getTailNode();
                        cout << "\n\nGUEST AT TAIL NODE" << endl;
                        cout << left << setw(26) << "    Name: " << temp_guest.getName() << endl;
                        cout << left << setw(26) << "    Age: " << temp_guest.getAge() << endl;
                        cout << left << setw(26) << "    Times Attended: " << temp_guest.getTimesAttended() << endl;
                        cout << left << setw(10) << "    Fl. Oz Baby Oil Used: " << temp_guest.getBbOilUsed() << endl;
                        break;
                    case 3:
                        party_list.displayList();
                        break;
                    default:
                        cout << "This shouldn't run :(" << endl;
                }
                    break;

            case 4:
                int list_order_choice;
                do{
                    cout << endl;
                    cout << "1. Sort in descending order" << endl;
                    cout << "2. Sort in ascending order" << endl;
                    cout << "Enter choice: ";
                    cin >> list_order_choice;
                    cout << "Choice input: " << list_order_choice << endl;
                }while(list_order_choice < 1 || list_order_choice > 2);

                party_list.selectionsort(list_order_choice-1);
                break;
        }
    }while(menuChoice != 5);
    
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