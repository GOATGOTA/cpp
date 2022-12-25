/*
Создать класс Octal 
(Класс для работы с беззнаковыми целыми восьмеричными числами, 
использует для представления числа массив из 100 элементов типа unsigned char, 
каждый элемент которого является восьмеричной цифрой.) 
и класс Hex 
(Класс для работы с беззнаковыми целыми шеснадцатеричными числами,
используя для представления числа массив из 100 элементов типа unsigned char, 
каждый из которых является шеснадцатеричной цифрой.)
*/

#include <iostream>

using namespace std;


class Octal
{
private:
   virtual void transform(const string& value) {
        size = value.length();
        int step = size - 1;
        int string_size = 0;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - size) {
                val[i] = value[string_size];
                int number = value[string_size] - '0';
                total_sum += number * pow(8, step);
                step--;
                string_size++;
            }
            else {
                val[i] = '0';
            }
        } 
    }
   virtual void display() {
       cout << "Это число в восьмеричной системе счисления!" << endl;
   }
public:
    enum { SIZE = 100 };

    unsigned char val[SIZE];
    unsigned int size = 0;
    int total_sum = 0;

    Octal () {}
    void init(const string& value)
    {
        transform(value);
    }
    void info() {
        display();
    }

    void full() {
        for (int i = 0; i < SIZE; i++) {
            cout << val[i];
        }
        cout << endl;
    }
        
    Octal operator + (const Octal& other) {
        Octal b = *this;
        b.total_sum += other.total_sum;
        int level = 0;
        bool flag = true;
        while (flag) {
            if (pow(8, level) > b.total_sum) {
                flag = false;
            }
            else {
                level++;
            }
        }
        b.size = level;
        level--;
        int fake_summ = b.total_sum;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - b.size) {
                b.val[i] = (int)(fake_summ/pow(8,level)) + '0';
                fake_summ -= (int)(fake_summ / pow(8, level)) * pow(8, level);
                level--;
            }
            else {
                val[i] = '0';
            }
        }
        return b;
    }

};

class Hex : public Octal {

private:
    void display() {
        cout << "Это число в шестнадцатеричной системе счисления!" << endl;
    }
    void transform(const string& value) override {
        size = value.length();
        int step = size - 1;
        int string_size = 0;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - size) {
                val[i] = value[string_size];
                int number;
                switch (value[string_size])
                {
                case 'A':
                    number = 10;
                    break;
                case 'B':
                    number = 11;
                    break;
                case 'C':
                    number = 12;
                    break;
                case 'D':
                    number = 13;
                    break;
                case 'E':
                    number = 14;
                    break;
                case 'F':
                    number = 15;
                    break;
                default:
                    number = value[string_size] - '0';
                }
                total_sum += number * pow(16, step);
                step--;
                string_size++;
            }
            else {
                val[i] = '0';
            }
        }
    }
    char transform(const int& number) {
        char letter;
        switch (number)
        {
        case 10:
            letter = 'A';
            break;
        case 11:
            letter = 'B';
            break;
        case 12:
            letter = 'C';
            break;
        case 13:
            letter = 'D';
            break;
        case 14:
            letter = 'E';
            break;
        case 15:
            letter = 'F';
            break;
        default:
            letter = number + '0';
        }
        return letter;
    }
public:
    Hex operator + (const Hex& other) {
        Hex b = *this;
        b.total_sum += other.total_sum;
        int level = 0;
        bool flag = true;
        while (flag) {
            if (pow(16, level) > b.total_sum) {
                flag = false;
            }
            else {
                level++;
            }
        }
        b.size = level;
        level--;
        int fake_summ = b.total_sum;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - b.size) {
                b.val[i] = transform((int)(fake_summ / pow(16, level)));
                fake_summ -= (int)(fake_summ / pow(16, level)) * pow(16, level);
                level--;
            }
            else {
                val[i] = '0';
            }
        }
        return b;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Octal a, b;
    a.init("65");
    b.init("12");
    Octal c = (a + b);
    c.full();
    cout << "total_sum = " << c.total_sum << "\t size = " << c.size << endl;
    Hex d, e;
    d.init("A0");
    e.init("1");
    Hex f = (d + e);
    f.full();
 

    return 0;
}