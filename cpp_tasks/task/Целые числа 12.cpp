// 2.12 min �� 3-�� ����� 

# include <iostream>
# include <stdio.h>
# include <math.h>
#include <algorithm>

using namespace std;


int main ()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c,d;
	cout << "�����: ";
	cin >> a;
	
	b = a % 10;
	c = a % 100 / 10;
	d = a / 100;
	
	cout << "sum:" << b + c + d << endl;
	
	cout << "proizv:" << b * c * d;

	
}
