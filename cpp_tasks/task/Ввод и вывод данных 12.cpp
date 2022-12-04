// Гипотенуза и катет прямоугольного треугольника

#include <iostream>
#include <cmath>
using namespace std;


int main(){
	
	setlocale(LC_ALL, "Russian");
	
	double a,b,c;
	
	cout << "Введите первый катет: ";
	cin >> a;
	cout << "Введите второй катет: ";
	cin >> b;
	c = sqrt(pow(a,2) + pow(b,2));
	
	cout << "Гипотенуза: " << c << endl;
	
	cout << "Периметр: " << a+b+c << endl;
}
