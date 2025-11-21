/*
Developer: Logan Taylor
Date: November 2, 2025
Purpose: Chada Tech Clocks – Displays two clocks (12-hour and 24-hour formats)
         side by side in neon colors and allows user interaction to add hours,
         minutes, or seconds. Demonstrates object-oriented programming,
         modular design, and best practices in C++.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// ANSI color codes for neon colors
#define GREEN "\033[1;92m"  // Bright neon green
#define RED   "\033[1;91m"  // Bright neon red
#define RESET "\033[0m"     // Reset color

// Function declarations
void displayClocks(int hour, int minute, int second);
void displayMenu();
void addHour(int& hour);
void addMinute(int& hour, int& minute);
void addSecond(int& hour, int& minute, int& second);

int main() {
    int hour = 12, minute = 0, second = 0;
    int menuChoice = 0;

    do {
        system("cls"); // Clear screen on Windows. Use system("clear") on Mac/Linux.

        displayClocks(hour, minute, second);
        displayMenu();
        cin >> menuChoice;

        switch (menuChoice) {
        case 1: addHour(hour); break;
        case 2: addMinute(hour, minute); break;
        case 3: addSecond(hour, minute, second); break;
        case 4: cout << "Program Finished." << endl; break;
        default: cout << "Invalid option. Please try again." << endl; break;
        }
    } while (menuChoice != 4);

    return 0;
}

// ---------------------------------------------------------------------------
// Display both 12-hour and 24-hour clocks side by side
// ---------------------------------------------------------------------------
void displayClocks(int hour, int minute, int second) {
    int hour12 = hour % 12;
    if (hour12 == 0) hour12 = 12;
    string am_pm = (hour >= 12) ? "PM" : "AM";

    const int clockWidth = 26;
    const int spaceBetween = 4;

    // Format 12-hour clock time string without color
    ostringstream time12;
    time12 << setw(2) << setfill('0') << hour12 << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second << " " << am_pm;
    string t12 = time12.str();

    // Format 24-hour clock time string without color
    ostringstream time24;
    time24 << setw(2) << setfill('0') << hour << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second;
    string t24 = time24.str();

    // Top border
    cout << string(clockWidth, '*') << string(spaceBetween, ' ')
        << string(clockWidth, '*') << endl;

    // Header row
    cout << "*     12-Hour Clock      *"
        << string(spaceBetween, ' ')
        << "*     24-Hour Clock      *" << endl;

    // Time row: manually pad so clocks align
    cout << "*  " << GREEN << t12 << RESET
        << string(clockWidth - 4 - t12.length(), ' ') << "*"
        << string(spaceBetween, ' ')
        << "*  " << RED << t24 << RESET
        << string(clockWidth - 4 - t24.length(), ' ') << "*" << endl;

    // Bottom border
    cout << string(clockWidth, '*') << string(spaceBetween, ' ')
        << string(clockWidth, '*') << endl;
}


// ---------------------------------------------------------------------------
// Display menu options
// ---------------------------------------------------------------------------
void displayMenu() {
    cout << endl;
    cout << "********************** Menu **********************" << endl;
    cout << "* 1 - Add One Hour                               *" << endl;
    cout << "* 2 - Add One Minute                             *" << endl;
    cout << "* 3 - Add One Second                             *" << endl;
    cout << "* 4 - Exit Program                               *" << endl;
    cout << "**************************************************" << endl;
    cout << "Please select an option (1-4): ";
}

// ---------------------------------------------------------------------------
// Add one hour, wrap around at 24
// ---------------------------------------------------------------------------
void addHour(int& hour) {
    hour = (hour + 1) % 24;
}

// ---------------------------------------------------------------------------
// Add one minute, increment hour if needed
// ---------------------------------------------------------------------------
void addMinute(int& hour, int& minute) {
    minute++;
    if (minute >= 60) {
        minute = 0;
        addHour(hour);
    }
}

// ---------------------------------------------------------------------------
// Add one second, increment minute/hour if needed
// ---------------------------------------------------------------------------
void addSecond(int& hour, int& minute, int& second) {
    second++;
    if (second >= 60) {
        second = 0;
        addMinute(hour, minute);
    }
}
