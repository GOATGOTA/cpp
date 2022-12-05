#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Place
{
	float first; // координата x
	float second; // координата y
	bool init(float f, float s)
	{
		if (f == 0 && s == 0)
			return false;
		else
		{
			first = f;
			second = s;
			return true;
		}
	}
	void read();
	void display();
	float distance() {
		if (first == 0)
			return abs(second);
		else if (second == 0)
			return abs(first);
		else
			return sqrt((first * first) + (second * second));

	}
};

void Place::display()
{
	cout << "POINT(" << first << ", " << second << ")";
}

void Place::read()
{
	float f = 0, s = 0;

	do
	{
		cout << "Задавать не нулевые координаты" << endl;
		cout << "Задайте координату x : "; cin >> f;
		cout << "Задайте координату y: "; cin >> s;

	}
	while (!init(f, s));
}

int main() {
	setlocale(LC_ALL, "Russian");
	Place p;
	p.read();
	p.display();
	cout << '\n' << p.distance();
	return 0;
}