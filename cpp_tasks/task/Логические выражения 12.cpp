// 3.12 ���� ��� ����� �����: A, B, C. 
// ��������� ���������� ������������: ������� �� ����� A, B, C �������������.

# include <iostream>
# include <windows.h>
# include <cmath>

using namespace std;

int main ()
{
	
	setlocale(LC_ALL, "Russian");
	
	double a,b,c;
	bool result;
	
	cout << "A: ";
	cin >> a;	
	cout << "B: ";
	cin >> b;
	cout << "C: ";
	cin >> c;
	
	result = a>0 && b>0 && c>0;
	
	cout << "return: " << boolalpha << result << endl;
	return 0;
  	

}
