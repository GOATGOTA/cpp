#include <iostream>
using namespace std;

int x, y;
int main(){
	setlocale(LC_ALL, "Russian");
	cout<<"Введите размерность массива по вертикали: ";
	cin>>x;
	cout<<"Введите размерность массива по горизонтали: ";
	cin>>y;
	int numbers[x][y];
	for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
        	cout<<"["<<i<<"]"<<"["<<j<<"]: ";
            cin>>numbers[i][j];
        }
    }
    
	bool flag;
	for (int i = 0; i < y; i++){
		flag = true;
		for (int j = 0; j < x; j++){
			if (numbers[j][i] % 2 == 0){
				flag = false;
				break;
			}
		}
		if (flag == true){
			cout<<"Номер столбца: "<<i+1<<endl;
			break;
		}
	}
	
	if (flag == false){
		cout<<0<<endl;
	}

	for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout<<numbers[i][j]<<" ";
        }
        cout<<endl;
    }
}
