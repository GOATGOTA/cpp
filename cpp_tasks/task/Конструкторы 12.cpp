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
    string surname;
    int accNum;
    float percent;
    float summa;

    void Init(string sur, int acc, float per, float sum)
    {
        surname = sur;
        accNum = acc;
        percent = per;
        summa = floor(sum * 100) / 100;
        Print();
    }

    void Print()
    {
        cout << "Surname: " << surname << "\nAccNum: " << accNum << "\nPercent: " << percent << "\nSumma: " << summa << endl << endl;
    }

    void ChangeName(string NewName)
    {
        surname = NewName;
        cout << "Имя изменено на " << NewName << endl << endl;
        Print();
    }

    void Withdraw(float money)
    {
        if (money > summa) {
            cout << "Баланс меньше суммы снятия!" << endl << endl;
        }
        else
        {
            summa -= money;
            cout << "Сумма в размере " << money << " снята с вашего счёта. Баланс: " << summa << endl << endl;
            Print();
        }
    }

    void Deposit(float money)
    {
        summa += money;
        cout << "Сумма в размере " << money << " зачислена на Ваш счёт. Баланс: " << summa << endl << endl;
    }

    void GetPercents(float percents)
    {
        percent += percents;
        cout << percents << " процент(ов) к Вашему счёту " << endl << endl;
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
        } else
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
    Account bill;
    bill.Init("Gotin", 5555, 2.5, 5000.24);
    bill.ChangeName("Myrov");
    bill.Withdraw(5000);
    bill.Deposit(5000);
    bill.GetPercents(5);
    bill.GetInDollars();
    bill.GetInEuro();
    bill.SummToString();
}

