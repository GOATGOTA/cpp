// 12.A в степени n

#include <iostream>

using namespace std;

int main() {
	
	
    setlocale(LC_ALL, "Russian");
    float a;
    cout << "Число:";
	cin >> a;
 
    int n;
    cout << "Степень:";
	cin >> n;
 
	float result;
	result = a;
    int i;
    for (i = 1; i < n; ++i)
        result *= a;
    cout << result;
}
