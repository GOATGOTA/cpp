#include <iostream>

using namespace std;

class Date {
protected:
    int day;
    int month;
    int year;

public:

    Date(int d, int m, int y) {
        try {
            day = Foo(d);
            month = Foo(m);
            year = Foo(y);
        }
        catch (const int ex) {
            cout << "Дата отрицательной не бывает!" << endl;
            exit;
        }
    }
    int Foo(int value) {
        if (value < 0) { throw value; }
        return value;
    }

    int diff(const Date& other) {
        int k = date(day, month, year) - date(other.day, other.month, other.year);
        return abs(k);
    }

private:
    bool vys(int year) {
        bool res = false;
        if (year % 4 == 0)
            res = true;
        if (year % 100 == 0)
            res = false;
        if (year % 400 == 0)
            res = true;
        return res;
    }

    int date(int d, int m, int y) {
        int k = d;
        if (vys(y) && (m > 2))
            k += y * 366;
        else k += y * 365;
        switch (m - 1) {
        case 12: k += 31;
        case 11: k += 30;
        case 10: k += 31;
        case  9: k += 30;
        case  8: k += 31;
        case  7: k += 31;
        case  6: k += 30;
        case  5: k += 31;
        case  4: k += 30;
        case  3: k += 31;
        case  2: k += 28;
        case  1: k += 31;
        }
        return k;
    }

};


int main()
{
    setlocale(LC_ALL, "ru");
    Date c(5, 4, 2003);
    Date b(0, 4, 2003);
    cout << b.diff(c) << endl;
    system("PAUSE");
}