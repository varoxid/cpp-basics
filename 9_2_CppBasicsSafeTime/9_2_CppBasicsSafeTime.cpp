#include <iostream>
#include <iomanip>
using namespace std;


class IllegalTimeException
{
public:
    IllegalTimeException() : message("Invalid time") {}
    void printMessage()  const { cout << message << endl; }
private:
    string message;
};

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
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
        hours(hours),
        minutes(minutes),
        seconds(seconds) {
        normalize();
    }

    void printFormattedTime() const {
        cout << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << endl;
    }

    Time add(const Time& time) const {
        Time result;
        result.seconds = seconds + time.seconds;
        result.minutes = minutes + time.minutes;
        result.hours = hours + time.hours;
        result.normalize();
        return result;
    }
};

int main() {
    try {
        const Time firstTime(2, 70, 90);
        const Time secondTime(1, 45, 30);

        cout << "First formatted time: ";
        firstTime.printFormattedTime();
        cout << "Second formatted time: ";
        secondTime.printFormattedTime();
        cout << "Result formatted time: ";
        firstTime.add(secondTime).printFormattedTime();

        const Time invalidTime(-1, 10, 30);
    } 
    catch (const IllegalTimeException& e) {
       e.printMessage();
    }
    return 0;
}