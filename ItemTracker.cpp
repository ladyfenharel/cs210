#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ItemTracker::readFile(const string& filename) {
    ifstream inFile(filename);
    string item;

    if (!inFile) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }

    while (inFile >> item) {
        itemCount[item]++;
    }
    inFile.close();
}

void ItemTracker::displayItemFrequency() const {
    cout << setw(15) << left << "Item" << "Frequency" << endl;
    cout << "-------------------------" << endl;
    for (const auto& pair : itemCount) {
        cout << setw(15) << left << pair.first << pair.second << endl;
    }
}

void ItemTracker::displayHistogram() const {
    for (const auto& pair : itemCount) {
        cout << setw(15) << left << pair.first << string(pair.second, '*') << endl;
    }
}

int ItemTracker::getItemFrequency(const string& item) const {
    auto it = itemCount.find(item);
    if (it != itemCount.end()) {
        return it->second;
    } else {
        return 0;
    }
}

void ItemTracker::writeBackupFile(const string& filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Cannot open backup file." << endl;
        return;
    }

    for (const auto& pair : itemCount) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();
}
