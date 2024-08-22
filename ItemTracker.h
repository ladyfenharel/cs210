#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

class ItemTracker {
private:
    std::map<std::string, int> itemCount;  // Map to store items and their frequencies

public:
    void readFile(const std::string& filename);          // Reads input file and counts item frequencies
    void displayItemFrequency() const;                   // Displays frequency of all items
    void displayHistogram() const;                       // Displays histogram of item frequencies
    int getItemFrequency(const std::string& item) const; // Returns the frequency of a specific item
    void writeBackupFile(const std::string& filename) const; // Writes item frequencies to a backup file
};

#endif
