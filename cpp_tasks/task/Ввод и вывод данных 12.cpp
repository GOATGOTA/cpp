// ���������� � ����� �������������� ������������

#include <iostream>
#include <cmath>
using namespace std;


int main(){
	
	setlocale(LC_ALL, "Russian");
	
	double a,b,c;
	
	cout << "������� ������ �����: ";
	cin >> a;
	cout << "������� ������ �����: ";
	cin >> b;
	c = sqrt(pow(a,2) + pow(b,2));
	
	cout << "����������: " << c << endl;
	
	cout << "��������: " << a+b+c << endl;
}
