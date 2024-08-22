#include <iostream>
#include <limits>
#include "ItemTracker.h"

using namespace std;

void printMenu();
int getValidatedInput(int min, int max);

int main() {
    ItemTracker tracker;
    string inputFilename = "CS210_Project_Three_Input_File.txt";
    string backupFilename = "frequency.dat";

    // Read input file and count item frequencies
    tracker.readFile(inputFilename);

    // Write backup file
    tracker.writeBackupFile(backupFilename);

    int option;

    do {
        printMenu();
        option = getValidatedInput(1, 4);

        switch(option) {
            case 1: {
                string searchItem;
                cout << "Enter the item to search for: ";
                cin >> searchItem;
                int frequency = tracker.getItemFrequency(searchItem);
                if (frequency > 0) {
                    cout << searchItem << " appears " << frequency << " times." << endl;
                } else {
                    cout << searchItem << " not found." << endl;
                }
                break;
            }
            case 2:
                tracker.displayItemFrequency();
                break;
            case 3:
                tracker.displayHistogram();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
        }

        cout << endl;
    } while (option != 4);

    return 0;
}

void printMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display histogram" << endl;
    cout << "4. Exit the program" << endl;
    cout << "Enter your choice: ";
}

int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}
