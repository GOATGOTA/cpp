#include <iostream>
// Дано целое число N > 1.
// Вывести наибольшее из целых чисел K, для которых сумма 1 + 2 + ... + K будет меньше или равна N, и саму эту сумму.
using namespace std;
 
int n;

int main(){
	setlocale(LC_ALL, "Russian");
	
	cout<<"Введите число: ";
	cin>>n;
	
	int summ = 0;
	int k = 0;
	
	
	while (summ + k + 1 <= n){
		k++;
		summ += k;
	}
	cout << k;

}

























