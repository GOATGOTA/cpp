#include <iostream>

using namespace std;

class Exception {};
class Exception_2 {
    string str;
public:
    Exception_2(const string& s) : str(s) {}
    void display() {
        cout << "Exception! - " << str << endl;
    }
};

class Exception_3 : public invalid_argument {
    int num;
public:
    Exception_3(const string msg, int n) : invalid_argument(msg), num(n) {}
    double err() const { return num; }
};

int time_1(int hours, int minutes, int seconds, int hours_2, int minutes_2, int seconds_2) {
    int a = 0, b = 0;
    a += hours * 60;
    a += minutes;
    if (seconds != 0) {
        a += 1;
    }
    b += hours_2 * 60;
    b += minutes_2;
    if (seconds_2 != 0) {
        b += 1;
    }
    return b - a;
}

int time_2(int hours, int minutes, int seconds, int hours_2, int minutes_2, int seconds_2) throw() {
    int a = 0, b = 0;
    a += hours * 60;
    a += minutes;
    if (seconds != 0) {
        a += 1;
    }
    b += hours_2 * 60;
    b += minutes_2;
    if (seconds_2 != 0) {
        b += 1;
    }
    return b - a;
}

int time_3(int hours, int minutes, int seconds, int hours_2, int minutes_2, int seconds_2) throw(invalid_argument) {
    if (hours == 0 && minutes == 0 && seconds == 0 && hours_2 == 0 && minutes_2 == 0 && seconds_2 == 0)
        throw invalid_argument("ZERO DATES");
    if (hours < 0 || minutes < 0 || seconds < 0 || hours_2 < 0 || minutes_2 < 0 || seconds_2 < 0)
        throw invalid_argument("TIME WITH MINUS?? 0_0");
    if (hours >= 24 || minutes >= 60 || seconds >= 60 || hours_2 >= 24 || minutes_2 >= 60 || seconds_2 >= 60) {
        throw invalid_argument("VARIABLES ARE OUT OF RANGE!");
    }
    int a = 0, b = 0;
    a += hours * 60;
    a += minutes;
    if (seconds != 0) {
        a += 1;
    }
    b += hours_2 * 60;
    b += minutes_2;
    if (seconds_2 != 0) {
        b += 1;
    }
    if (b - a < 0) {
        throw invalid_argument("NEGATIVE LENGTH");
    }
    return b - a;
}

int time_4(int hours, int minutes, int seconds, int hours_2, int minutes_2, int seconds_2) throw(Exception) {
    if (hours == 0 && minutes == 0 && seconds == 0 && hours_2 == 0 && minutes_2 == 0 && seconds_2 == 0)
        throw Exception();
    if (hours < 0 || minutes < 0 || seconds < 0 || hours_2 < 0 || minutes_2 < 0 || seconds_2 < 0)
        throw Exception();
    if (hours >= 24 || minutes >= 60 || seconds >= 60 || hours_2 >= 24 || minutes_2 >= 60 || seconds_2 >= 60) {
        throw Exception();
    }
    int a = 0, b = 0;
    a += hours * 60;
    a += minutes;
    if (seconds != 0) {
        a += 1;
    }
    b += hours_2 * 60;
    b += minutes_2;
    if (seconds_2 != 0) {
        b += 1;
    }
    if (b - a < 0) {
        throw Exception();
    }
    return b - a;
}

int time_5(int hours, int minutes, int seconds, int hours_2, int minutes_2, int seconds_2) throw(Exception_2) {
    if (hours == 0 && minutes == 0 && seconds == 0 && hours_2 == 0 && minutes_2 == 0 && seconds_2 == 0)
        throw Exception_2("ZERO DATES");
    if (hours < 0 || minutes < 0 || seconds < 0 || hours_2 < 0 || minutes_2 < 0 || seconds_2 < 0)
        throw Exception_2("TIME WITH MINUS?? 0_0");
    if (hours >= 24 || minutes >= 60 || seconds >= 60 || hours_2 >= 24 || minutes_2 >= 60 || seconds_2 >= 60) {
        throw Exception_2("VARIABLES ARE OUT OF RANGE!");
    }
    int a = 0, b = 0;
    a += hours * 60;
    a += minutes;
    if (seconds != 0) {
        a += 1;
    }
    b += hours_2 * 60;
    b += minutes_2;
    if (seconds_2 != 0) {
        b += 1;
    }
    if (b - a < 0) {
        throw Exception_2("NEGATIVE LENGTH!");
    }
    return b - a;
}

int time_6(int hours, int minutes, int seconds, int hours_2, int minutes_2, int seconds_2) throw(Exception_3) {
    if (hours == 0 && minutes == 0 && seconds == 0 && hours_2 == 0 && minutes_2 == 0 && seconds_2 == 0)
        throw Exception_3("ZERO DATES", 000);
    if (hours < 0 || minutes < 0 || seconds < 0 || hours_2 < 0 || minutes_2 < 0 || seconds_2 < 0)
        throw Exception_3("TIME WITH MINUS?? 0_0", -999999);
    if (hours >= 24 || minutes >= 60 || seconds >= 60 || hours_2 >= 24 || minutes_2 >= 60 || seconds_2 >= 60) {
        throw Exception_3("VARIABLES ARE OUT OF RANGE!", 999999);
    }
    int a = 0, b = 0;
    a += hours * 60;
    a += minutes;
    if (seconds != 0) {
        a += 1;
    }
    b += hours_2 * 60;
    b += minutes_2;
    if (seconds_2 != 0) {
        b += 1;
    }
    if (b - a < 0) {
        throw Exception_3("NEGATIVE LENGTH!", -999);
    }
    return b - a;
}

void init(int (*func)(int, int, int, int, int, int)) {
    int hours, minutes, seconds, hours_2, minutes_2, seconds_2;
    cout << "HOURS FIRST: ";
    cin >> hours;
    cout << "MINUTES FIRST: ";
    cin >> minutes;
    cout << "SECONDS FIRST: ";
    cin >> seconds;
    cout << "HOURS SECOND: ";
    cin >> hours_2;
    cout << "MINUTES SECOND: ";
    cin >> minutes_2;
    cout << "SECONDS SECOND: ";
    cin >> seconds_2;
    cout << "DURATION: " << func(hours, minutes, seconds, hours_2, minutes_2, seconds_2) << endl << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Вычисление длительности разговора\n";

    try {
        init(time_1);
    }
    catch (...) {
        cout << "ERROR time_1" << endl;
    }

    try {
        init(time_2);
    }
    catch (...) {
        cout << "ERROR time_2" << endl;
    }

    try {
        init(time_3);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        init(time_4);
    }
    catch (Exception) {
        cout << "EXCEPTION IN time_4" << endl;
    }

    try {
        init(time_5);
    }
    catch (Exception_2& e) {
        e.display();
    }

    try {
        init(time_6);
    }
    catch (Exception_3& e) {
        cout << e.what() << "\n # Error " << e.err() << endl;
    }
}