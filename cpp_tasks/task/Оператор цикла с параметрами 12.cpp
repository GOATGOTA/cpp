// 12.A � ������� n

#include <iostream>

using namespace std;

int main() {
	
	
    setlocale(LC_ALL, "Russian");
    float a;
    cout << "�����:";
	cin >> a;
 
    int n;
    cout << "�������:";
	cin >> n;
 
	float result;
	result = a;
    int i;
    for (i = 1; i < n; ++i)
        result *= a;
    cout << result;
}
