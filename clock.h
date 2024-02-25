#include <iostream>

class Clock {
private:
    int seconds; 
    int minutes; 
    int hours; 
    int days; 

    void adjustTimeComponents(int totalSec);

public: 
    // Constructors
    Clock();
    Clock(int newDays);
    Clock(int newMinutes, int newSeconds);
    Clock(int newDays, int newHours, int newMinutes, int newSeconds); 

    // Operator overloads
    Clock operator-() const;
    Clock operator+(const Clock& other) const;
    Clock operator-(const Clock& other) const;
    bool operator==(const Clock& other) const;
    bool operator<(const Clock& other) const;
    bool operator>(const Clock& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Clock& clock);

    // Getters
    int GetSeconds() const;
    int GetMinutes() const;
    int GetHours() const; 
    int GetDays() const; 

    // Setters
    bool SetSeconds(int seconds);
    bool SetMinutes(int minutes); 
    bool SetHours(int hours); 
    bool SetDays(int days);

    // Member functions
    void Reset(); 
    // void fixOverFlow(); 
    // void ConvertSectoDay(int n); 

    int GetTotalSeconds() const;
};