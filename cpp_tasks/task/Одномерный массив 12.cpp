#include <iostream>
// ��� ������ A ������� N. ����� ������������ ������� �� ��� ��������� � ��������� �������� 
using namespace std;
 
int x;

int main(){
	setlocale(LC_ALL, "Russian");
	
	cout<<"������� ����������� �������: ";
	cin>>x;
	if (x == 0){
		return 0;
	}
	int numbers[x];
	for (int i = 0; i < x; i++){
		cout<<"["<<i<<"] ";
            cin>>numbers[i];
	}
	
	int max=numbers[0];
	
	for (int i=0; i<x; i+=2){
		if (numbers[i]>max){
			max=numbers[i];
		}
    }
	
	cout<<"Max: "<<max<<endl;
	
}
