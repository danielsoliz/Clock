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

// Setters
bool Clock::SetSeconds(int s) {
    seconds = s;
    fixOverFlow();
    return true;
}

bool Clock::SetMinutes(int m) {
    minutes = m;
    fixOverFlow();
    return true;
}

bool Clock::SetHours(int h) {
    hours = h;
    fixOverFlow();
    return true;
}

bool Clock::SetDays(int d) {
    days = d;
    fixOverFlow();
    return true;
}

void Clock::fixOverFlow() {
    int totalSeconds = GetSeconds() + GetMinutes() * 60 + GetHours() * 3600 + GetDays() * 86400;
    ConvertSectoDay(totalSeconds);
}

void Clock::ConvertSectoDay(int n) {
    SetDays(n / (24 * 3600));
    n %= (24 * 3600);
    SetHours(n / 3600);
    n %= 3600;
    SetMinutes(n / 60);
    SetSeconds(n % 60);
}

// Overloading the unary minus operator
Clock Clock::operator-() const {
    return Clock(-GetDays(), -GetHours(), -GetMinutes(), -GetSeconds());
}

// Overloading the addition operator
Clock Clock::operator+(const Clock& other) const {
    int totalSeconds1 = (GetDays() * 86400) + (GetHours() * 3600) + (GetMinutes() * 60) + GetSeconds();
    int totalSeconds2 = (other.GetDays() * 86400) + (other.GetHours() * 3600) + (other.GetMinutes() * 60) + other.GetSeconds();
    int totalSecondsResult = totalSeconds1 + totalSeconds2;

    Clock result;
    result.ConvertSectoDay(totalSecondsResult);
    return result;
}

// Overloading the subtraction operator
Clock Clock::operator-(const Clock& other) const {
    int totalSeconds1 = (GetDays() * 86400) + (GetHours() * 3600) + (GetMinutes() * 60) + GetSeconds();
    int totalSeconds2 = (other.GetDays() * 86400) + (other.GetHours() * 3600) + (other.GetMinutes() * 60) + other.GetSeconds();
    int totalSecondsResult = totalSeconds1 - totalSeconds2;

    Clock result;
    result.ConvertSectoDay(abs(totalSecondsResult));
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
