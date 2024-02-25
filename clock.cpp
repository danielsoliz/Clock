#include "clock.h"
#include <iostream>
#include <cmath>

Clock::Clock() {
    SetDays(0);
    SetHours(0);
    SetMinutes(0);
    SetSeconds(0);
}

Clock::Clock(int newDays) {
    if (!SetDays(newDays)) SetDays(0);
}

Clock::Clock(int newMinutes, int newSeconds) {
    if (!SetMinutes(newMinutes)) SetMinutes(0);
    if (!SetSeconds(newSeconds)) SetSeconds(0);
}

Clock::Clock(int newDays, int newHours, int newMinutes, int newSeconds) {
    SetDays(newDays);
    SetHours(newHours);
    SetMinutes(newMinutes);
    SetSeconds(newSeconds);
    adjustTimeComponents(GetTotalSeconds());
}

// Getters
int Clock::GetDays() const {
    return days;
}

int Clock::GetHours() const {
    return hours;
}

int Clock::GetMinutes() const {
    return minutes;
}

int Clock::GetSeconds() const {
    return seconds;
}

// Corrected Setters
bool Clock::SetSeconds(int s) {
    seconds = s;
    return true;
}

bool Clock::SetMinutes(int m) {
    minutes = m;
    return true;
}

bool Clock::SetHours(int h) {
    hours = h;
    return true;
}

bool Clock::SetDays(int d) {
    days = d;
    return true;
}

int Clock::GetTotalSeconds() const {
    return seconds + (minutes * 60) + (hours * 3600) + (days * 86400);
}

void Clock::adjustTimeComponents(int totalSeconds) {
    // Calculate each component
    int newDays = totalSeconds / (24 * 3600);
    totalSeconds %= (24 * 3600); // Update totalSeconds after calculating days
    int newHours = totalSeconds / 3600;
    totalSeconds %= 3600; // Update totalSeconds after calculating hours
    int newMinutes = totalSeconds / 60;
    int newSeconds = totalSeconds % 60; // Remainder is the new seconds value

    // Use setters to update the class members
    SetDays(newDays);
    SetHours(newHours);
    SetMinutes(newMinutes);
    SetSeconds(newSeconds);
}

// Overloading the unary minus operator
Clock Clock::operator-() const {
    return Clock(-GetDays(), -GetHours(), -GetMinutes(), -GetSeconds());
}

// Overloading the addition operator
Clock Clock::operator+(const Clock& other) const {
    int totalSeconds1 = GetTotalSeconds(); // Utilize the existing method to get total seconds
    int totalSeconds2 = other.GetTotalSeconds(); // Same for the other Clock
    int totalSecondsResult = totalSeconds1 + totalSeconds2;

    Clock result;
    // Use adjustTimeComponents to set the result Clock's time based on the total seconds result
    result.adjustTimeComponents(totalSecondsResult);
    return result;
}

Clock Clock::operator-(const Clock& other) const {
    int totalSeconds1 = GetTotalSeconds(); // Utilize the existing method to get total seconds
    int totalSeconds2 = other.GetTotalSeconds(); // Same for the other Clock
    int totalSecondsResult = totalSeconds1 - totalSeconds2;

    Clock result;
    // Use adjustTimeComponents directly to set the result Clock's time based on absolute value of totalSecondsResult
    result.adjustTimeComponents(abs(totalSecondsResult));
    // The concept of negating a Clock object (-result) is removed since it's not defined how to negate time meaningfully
    return totalSecondsResult < 0 ? -result : result;
}

// Comparison operators
bool Clock::operator==(const Clock& other) const {
    return GetDays() == other.GetDays() && GetHours() == other.GetHours() &&
           GetMinutes() == other.GetMinutes() && GetSeconds() == other.GetSeconds();
}

bool Clock::operator<(const Clock& other) const {
    if (GetDays() != other.GetDays()) return GetDays() < other.GetDays();
    if (GetHours() != other.GetHours()) return GetHours() < other.GetHours();
    if (GetMinutes() != other.GetMinutes()) return GetMinutes() < other.GetMinutes();
    return GetSeconds() < other.GetSeconds();
}

bool Clock::operator>(const Clock& other) const {
    if (GetDays() != other.GetDays()) return GetDays() > other.GetDays();
    if (GetHours() != other.GetHours()) return GetHours() > other.GetHours();
    if (GetMinutes() != other.GetMinutes()) return GetMinutes() > other.GetMinutes();
    return GetSeconds() > other.GetSeconds();
}


std::ostream& operator<<(std::ostream& os, const Clock& clock) {
    os << "Days: " << clock.GetDays() << ", Hours: " << clock.GetHours()
       << ", Minutes: " << clock.GetMinutes() << ", Seconds: " << clock.GetSeconds();
    return os;
}

void Clock::Reset() {
    SetDays(0);
    SetHours(0);
    SetMinutes(0);
    SetSeconds(0);
}
