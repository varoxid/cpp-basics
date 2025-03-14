#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    int getSeconds() {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time addTime(Time& time) {
        Time result{};
        int totalSeconds = getSeconds() + time.getSeconds();

        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;

        return result;
    }

    Time subtractTime(Time& time) {
        Time result{};
        int totalSeconds = getSeconds() - time.getSeconds();

        if (totalSeconds < 0) {
            cerr << "Invalid result" << endl;
            return { 0, 0, 0 };
        }

        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;

        return result;
    }
};

static Time inputTime() {
    cout << "Enter time:" << endl;
    Time time{};
    cout << "Enter hours: ";
    cin >> time.hours;
    cout << "Enter minutes: ";
    cin >> time.minutes;
    cout << "Enter seconds: ";
    cin >> time.seconds;

    if (time.hours < 0 
        || time.minutes < 0 
        || time.minutes >= 60 
        || time.seconds < 0
        || time.seconds >= 60) {
        cerr << "Invalid time" << endl;
        exit(1);
    }

    return time;
}

int main() {
    Time firstTime = inputTime();
    Time secondTime = inputTime();

    cout << "Input seconds: " << firstTime.getSeconds() << endl;

    Time sum = firstTime.addTime(secondTime);
    cout << "Result: "
        << sum.hours << " hours, "
        << sum.minutes << " minutes, "
        << sum.seconds << " seconds." << endl;

    Time result = firstTime.subtractTime(secondTime);
    cout << "Result: "
        << result.hours << " hours, "
        << result.minutes << " minutes, "
        << result.seconds << " seconds." << endl;

    return 0;
}