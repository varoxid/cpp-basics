#include <iostream>
#include <iomanip>
using namespace std;

class IllegalTimeException {
public:
    IllegalTimeException() : message("Invalid time") {}
    void printMessage() const { cout << message << endl; }
private:
    string message;
};

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void doConvertions() {
        if (hours < 0 || minutes < 0 || seconds < 0) {
            throw IllegalTimeException();
        }
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int hours, int minutes, int seconds) :
        hours(hours), minutes(minutes), seconds(seconds) {
        doConvertions();
    }

    Time operator+(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes;
        result.hours = hours + other.hours;
        result.doConvertions();
        return result;
    }

    Time operator-(const Time& time) const {
        Time result;
        result.seconds = seconds - time.seconds;
        result.minutes = minutes - time.minutes;
        result.hours = hours - time.hours;
        result.doConvertions();
        return result;
    }

    Time operator+(double seconds) const {
        Time result;
        result.seconds = seconds + static_cast<int>(seconds);
        result.minutes = minutes;
        result.hours = hours;
        result.doConvertions();
        return result;
    }

    friend Time operator+(double secondsToAdd, const Time& time);
    
    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

    bool operator==(const Time& other) const {
        return hours == other.hours 
            && minutes == other.minutes 
            && seconds == other.seconds;
    }

    bool operator<(const Time& time) const {
        if (hours < time.hours) {
            return true;
        }
        if (hours == time.hours 
            && minutes < time.minutes) {
            return true;
        }
        if (hours == time.hours 
            && minutes == time.minutes 
            && seconds < time.seconds) {
            return true;
        }
        return false;
    }

    bool operator>=(const Time& time) const {
        return !(*this < time);
    }
    bool operator<=(const Time& other) const {
        return !(*this > other);
    }
    bool operator>(const Time& other) const {
        return other < *this;
    }

    void printFormattedTime() const {
        cout << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << endl;
    }
};

Time operator+(double secondsToAdd, const Time& time) {
    return time + secondsToAdd;
}

int main() {
    try {
        const Time firstTime(2, 70, 90);
        const Time secondTime(1, 45, 30);

        cout << "First formatted time: ";
        firstTime.printFormattedTime();
        cout << "Second formatted time: ";
        secondTime.printFormattedTime();

        Time sumTime = firstTime + secondTime;
        cout << "Sum: ";
        sumTime.printFormattedTime();

        Time subtractTime = firstTime - secondTime;
        cout << "Subtract: ";
        subtractTime.printFormattedTime();

        Time timeAddSecondsResult = firstTime + 11.7;
        cout << "Add 11.7 seconds: ";
        timeAddSecondsResult.printFormattedTime();

        Time secondsAddTimeResult = 99.0 + firstTime;
        cout << "99.0 seconds + Time: ";
        secondsAddTimeResult.printFormattedTime();

        if (firstTime == secondTime) {
            cout << "Times are equal." << endl;
        }
        else if (firstTime < secondTime) {
            cout << "First less than second" << endl;
        }
        else {
            cout << "First is greater than second" << endl;
        }

        const Time invalidTime(-1, 10, 30);
    }
    catch (const IllegalTimeException& e) {
        e.printMessage();
    }

    return 0;
}