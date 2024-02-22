#include "Clock.h"
#include <iostream>
#include <string>

int main() {
    Clock clock;  // Create a Clock instance with default time 0:0:0:0
    Clock comparisonClock; // For comparison operations
    int choice = 0;

    do {
        std::cout << "\nClock Management System\n";
        std::cout << "1. Set Time\n";
        std::cout << "2. Add Time\n";
        std::cout << "3. Subtract Time\n";
        std::cout << "4. Display Time\n";
        std::cout << "5. Negate Time\n";
        std::cout << "6. Compare Time\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {  // Set Time
                int days, hours, minutes, seconds;
                std::cout << "Enter days, hours, minutes, and seconds: ";
                std::cin >> days >> hours >> minutes >> seconds;
                clock = Clock(days, hours, minutes, seconds);  // Resetting time
                break;
            }
            case 2: {  // Add Time
                int days, hours, minutes, seconds;
                std::cout << "Enter days, hours, minutes, and seconds to add: ";
                std::cin >> days >> hours >> minutes >> seconds;
                Clock temp(days, hours, minutes, seconds);
                clock = clock + temp;  // Adding time
                break;
            }
            case 3: {  // Subtract Time
                int days, hours, minutes, seconds;
                std::cout << "Enter days, hours, minutes, and seconds to subtract: ";
                std::cin >> days >> hours >> minutes >> seconds;
                Clock temp(days, hours, minutes, seconds);
                clock = clock - temp;  // Subtracting time
                break;
            }
            case 4: {  // Display Time
            std::cout << "Current Time: "
                    << clock.GetDays() << " days, "
                    << clock.GetHours() << " hours, "
                    << clock.GetMinutes() << " minutes, "
                    << clock.GetSeconds() << " seconds\n";
            break;
            }
            case 5: {  // Negate Time
                clock = -clock;  // Negating time
                std::cout << "Time negated.\n";
                break;
            }
            case 6: {  // Compare Time
                int days, hours, minutes, seconds;
                std::cout << "Enter days, hours, minutes, and seconds for the clock to compare: ";
                std::cin >> days >> hours >> minutes >> seconds;
                comparisonClock = Clock(days, hours, minutes, seconds);
                std::cout << "Comparing...\n";
                if (clock == comparisonClock) std::cout << "Clocks are equal.\n";
                else if (clock < comparisonClock) std::cout << "First clock is less than the second.\n";
                else if (clock > comparisonClock) std::cout << "First clock is greater than the second.\n";
                break;
            }
            case 7:  // Exit
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// g++ -o clock.exe main.cpp clock.cpp