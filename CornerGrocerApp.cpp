// Dunn - CS 210 Project Three.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include "GroceryItem.h"
using namespace std;


//Displays the main menu options for the user
//@returns - nothing
//@throws - nothing
void displayMenu() {
    cout << endl;
    cout << "----Menu----" << endl;
    cout << "1: Search for an Item" << endl;
    cout << "2: Display all Item Frequencies" << endl;
    cout << "3: Display Histogram of Item Frequencies" << endl;
    cout << "4: Exit Program" << endl;
    cout << "Enter your choice: (1-4)" << endl;
}

//Program start point. Handles menu navigation and user interaction.
//@param - none
//@returns - 0 upon successful completion
//@throws - nothing
int main() {
    string inFile = "inventory.txt";

    GroceryItem::loadFile(inFile);
    GroceryItem::writeBackupFile();

    int menuChoice = 0;
    string item;

    const int SEARCH_ITEM = 1;
    const int DISPLAY_FREQUENCIES = 2;
    const int DISPLAY_HISTOGRAM = 3;
    const int EXIT_PROGRAM = 4;

    //Loop continues until the user selects the exit option
    while (menuChoice != EXIT_PROGRAM) {
        displayMenu();

        cin >> menuChoice;

        //Validates user input and forces input reentry until a valid menu choice is provided
        while (cin.fail() || menuChoice < 1 || menuChoice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a number (1-4)" << endl;
            cin >> menuChoice;
        }

        switch (menuChoice) {

            case SEARCH_ITEM: {
                
                //Reloads inventory data to ensure the most recent data is used
                if (!GroceryItem::loadFile(inFile)) {
                    cout << "Error: could not open inventory file." << endl;
                }

                cout << "Enter an item: (capitalized)" << endl;
                cin >> item;
                cout << endl;

                GroceryItem* lookup = GroceryItem::itemLookup(item);

                //Checks if the lookup returned a valid item before accessing data
                if (lookup != nullptr) {
                    cout << lookup->getName() << ": " << lookup->getQuantity() << endl;
                }
                else {
                    cout << "Item not found." << endl;
                }
                break;
            }

            case DISPLAY_FREQUENCIES:

                //Reloads inventory data to ensure the most recent data is used
                if (!GroceryItem::loadFile(inFile)) {
                    cout << "Error: could not open inventory file." << endl;
                }

                for (const auto& pair : GroceryItem::getInventory()) {
                    cout << pair.first << ": " << pair.second->getQuantity() << endl;
                }
                break;

            case DISPLAY_HISTOGRAM:

                //Reloads inventory data to ensure the most recent data is used
                if (!GroceryItem::loadFile(inFile)) {
                    cout << "Error: could not open inventory file." << endl;
                }

                for (const auto& pair : GroceryItem::getInventory()) {

                    //Builds a histogram by repeating '*' for the quantity of the item
                    cout << pair.first << ": " << string(pair.second->getQuantity(), '*') << endl;
                }

                break;

            case EXIT_PROGRAM:

                break;

        }
    }
}