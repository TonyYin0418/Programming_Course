#include <iostream>
#include <stdio.h>
using namespace std;

class Time {
public:
    int hour, minute, second;
    friend ostream& operator<<(ostream& os, const Time& t) {
        char buffer[10];
        sprintf(buffer, "%02d:%02d:%02d\n", t.hour, t.minute, t.second);
        os << buffer;
        return os;
    }
    friend istream& operator>>(istream& is, Time& t) {
        is >> t.hour >> t.minute >> t.second;
        return is;
    }
    Time& operator+=(const Time& other) {
        second += other.second;
        minute += second / 60 + other.minute;
        hour += minute / 60 + other.hour;
        hour %= 24;
        minute %= 60;
        second %= 60;
        return *this;
    }
    Time& operator-=(const Time& other) {
        hour -= other.hour;
        minute -= other.minute;
        second -= other.second;
        if(second < 0) {
            minute -= (-second + 59) / 60;
            second = (second % 60 + 60) % 60;
        }
        if(minute < 0) {
            hour -= (-minute + 59) / 60;
            minute = (minute % 60 + 60) % 60;
        }
        hour = (hour % 24 + 24) % 24;
        return *this;
    }
    Time& operator++() {
        second++;
        if(second >= 60) {
            second = 0;
            minute++;
            if(minute == 60) {
                minute = 0;
                hour = (hour + 1) % 24;
            }
        }
        return *this;
    }
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }
    Time& operator--() {
        second--;
        if(second == -1) {
            second = 59;
            minute--;
            if(minute == -1) {
                minute = 59;
                hour = (hour + 23) % 24;
            }
        }
        return *this;
    }
    Time operator--(int) {
        Time old = *this;
        --(*this);
        return old;
    }
};

int main() {
    Time time1, time2;
    cin >> time1;
    cin >> time2;
    cout << (time1 += (time2++));
    cout << (time1 -= time2);
    cout << (++time2);
    cout << (time2 += (time1--));
    cout << (--time1);
    cout << (time2 -= time1);
    return 0;
}

