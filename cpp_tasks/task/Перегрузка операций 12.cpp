#include <iostream>
#include <conio.h>
#include <math.h>
#include <cmath>
using namespace std;
/*
Реализовать класс Account, представляющий собой банковский счет.
В классе должны быть четыре поля: фамилия владельца, номер счета, процент начисления и сумма в рублях.
Открытие нового счета выполняется операцией инициализации.
Необходимо выполнить следующие операции:
сменить владельца счета, снять некоторую сумму денег со счета,
положить деньги на счет, начислить проценты,
перевести сумму в доллары, перевести сумму в евро,
получить сумму прописью (преобразовать в численное)
*/

const double DOLLAR = 60;
const double EURO = 75;
class Account {
public:
    Account(const Account& other) {
        this->surname = other.surname;
        this->accNum = other.accNum;
        this->percent = other.percent;
        this->summa = other.summa;
        this->size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    Account() {}

    Account(string sur, int acc, float per, float sum, int size) {
        this->surname = sur;
        this->accNum = acc;
        this->percent = per;
        this->summa = sum;
        this->size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    Account& operator = (const Account& other) {
        this->surname = other.surname;
        this->accNum = other.accNum;
        this->percent = other.percent;
        this->summa = other.summa;
        this->size = other.size;

        if (this->data != nullptr) {
            delete[] this->data;
        }

        this->data = new int[other.size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }

        return *this;
    }

    Account& operator + (const double& other) {
        this->summa += other;

        return *this;
    }

    Account& operator - (const double& other) {
        this->summa -= other;

        return *this;
    }






    ~Account() { delete[] data; }


private:
    string surname;
    int accNum;
    float percent;
    float summa;
    int* data;
    int size;

public:
    void ChangeName(string surname)
    {
        this->surname = surname;
        cout << "Имя изменено на " << surname << endl << endl;
        Print();
    }

    void Withdraw(float money)
    {
        if (money > this->summa) {
            cout << "Баланс меньше суммы снятия!" << endl << endl;
        }
        else
        {
            this->summa -= money;
            cout << "Сумма в размере " << money << " снята с вашего счёта. Баланс: " << this->summa << endl << endl;
            Print();
        }
    }

    void Deposit(float money)
    {
        this->summa += money;
        cout << "Сумма в размере " << money << " зачислена на Ваш счёт. Баланс: " << this->summa << endl << endl;
    }

    void GetPercents(float percent)
    {
        this->percent += percent;
        cout << percent << " процент(ов) к Вашему счёту " << endl << endl;
        Print();

    }

    void GetInDollars()
    {
        if (summa > 0) {
            float balance = summa;
            balance = balance / DOLLAR;
            balance = floor(balance * 100) / 100;
            cout << balance << " $ " << endl << endl;
        }
        else if (summa = 0) {
            cout << "0 $ " << endl << endl;
        }
    }

    void GetInEuro()
    {
        if (summa > 0) {
            float balance = summa;
            balance = balance / EURO;
            balance = floor(balance * 100) / 100;
            cout << balance << " euro(s) " << endl << endl;
        }
        else if (summa = 0) {
            cout << "0 euro " << endl << endl;
        }
    }

    void SummToString()
    {
        double fractpart, intpart;
        fractpart = modf(summa, &intpart);
        int a = intpart;
        if (a < 0) {
            cout << "Минусовое число";
        }
        if (a == 0) {
            cout << "ноль";
        }
        else
        {
            switch (a / 1000)
            {
            case 1: cout << "одна тысяча"; break;
            case 2: cout << "две тысячи"; break;
            case 3: cout << "три тысячи"; break;
            case 4: cout << "четыре тысячи"; break;
            case 5: cout << "пять тысяч"; break;
            case 6: cout << "шесть тысяч"; break;
            case 7: cout << "семь тысяч"; break;
            case 8: cout << "восемь тысяч"; break;
            case 9: cout << "девять тысяч"; break;
            }

            switch ((a % 1000) / 100)
            {
            case 1: cout << " сто"; break;
            case 2: cout << " двести"; break;
            case 3: cout << " триста"; break;
            case 4: cout << " четыреста"; break;
            case 5: cout << " пятсот"; break;
            case 6: cout << " шестьсот"; break;
            case 7: cout << " семьсот"; break;
            case 8: cout << " восемьсот"; break;
            case 9: cout << " девятьсот"; break;
            }

            switch ((a % 100) / 10)
            {
            case 2: cout << " двадцать"; break;
            case 3: cout << " тридцать"; break;
            case 4: cout << " сорок"; break;
            case 5: cout << " пятдесят"; break;
            case 6: cout << " шестьдесят"; break;
            case 7: cout << " семьдесят"; break;
            case 8: cout << " восемьдесят"; break;
            case 9: cout << " девяносто"; break;
            }

            if (((a % 100) >= 10) && ((a % 100) < 20)) {
                switch (a % 100) {
                case 10: cout << " десять"; break;
                case 11: cout << " одинадцать"; break;
                case 12: cout << " двенадцать"; break;
                case 13: cout << " тринадцать"; break;
                case 14: cout << " четырнадцать"; break;
                case 15: cout << " пятнадцать"; break;
                case 16: cout << " шестнадцать"; break;
                case 17: cout << " семнадцать"; break;
                case 18: cout << " восемнадцать"; break;
                case 19: cout << " девятнадцать"; break;
                }
            }
            else {
                switch (a % 10)
                {
                case 1: cout << " один"; break;
                case 2: cout << " два"; break;
                case 3: cout << " три"; break;
                case 4: cout << " четыре"; break;
                case 5: cout << " пять"; break;
                case 6: cout << " шесть"; break;
                case 7: cout << " семь"; break;
                case 8: cout << " восемь"; break;
                case 9: cout << " девять"; break;
                }
            }
        }
        if (fractpart != 0) {
            cout << " и";
            a = round(fractpart * 100);
            switch ((a % 100) / 10)
            {
            case 2: cout << " двадцать"; break;
            case 3: cout << " тридцать"; break;
            case 4: cout << " сорок"; break;
            case 5: cout << " пятдесят"; break;
            case 6: cout << " шестьдесят"; break;
            case 7: cout << " семьдесят"; break;
            case 8: cout << " восемьдесят"; break;
            case 9: cout << " девяносто"; break;
            }

            if (((a % 100) >= 10) && ((a % 100) < 20)) {
                switch (a % 100) {
                case 10: cout << " десять"; break;
                case 11: cout << " одинадцать"; break;
                case 12: cout << " двенадцать"; break;
                case 13: cout << " тринадцать"; break;
                case 14: cout << " четырнадцать"; break;
                case 15: cout << " пятнадцать"; break;
                case 16: cout << " шестнадцать"; break;
                case 17: cout << " семнадцать"; break;
                case 18: cout << " восемнадцать"; break;
                case 19: cout << " девятнадцать"; break;
                }
            }
            else {
                switch (a % 10)
                {
                case 0: cout << " ноль"; break;
                case 1: cout << " один"; break;
                case 2: cout << " два"; break;
                case 3: cout << " три"; break;
                case 4: cout << " четыре"; break;
                case 5: cout << " пять"; break;
                case 6: cout << " шесть"; break;
                case 7: cout << " семь"; break;
                case 8: cout << " восемь"; break;
                case 9: cout << " девять"; break;
                }
            }
        }
        cout << endl << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    Account bill("Gotin", 5555, 2.5, 5000.24, 5);
    double deposit = 1000;
    bill + deposit;




}
