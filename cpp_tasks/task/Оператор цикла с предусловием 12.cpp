#include <iostream>
// ���� ����� ����� N > 1.
// ������� ���������� �� ����� ����� K, ��� ������� ����� 1 + 2 + ... + K ����� ������ ��� ����� N, � ���� ��� �����.
using namespace std;
 
int n;

int main(){
	setlocale(LC_ALL, "Russian");
	
	cout<<"������� �����: ";
	cin>>n;
	
	int summ = 0;
	int k = 0;
	
	
	while (summ + k + 1 <= n){
		k++;
		summ += k;
	}
	cout << k;

}

























