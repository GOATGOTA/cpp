#include <iostream>
#include <string>
#include <vector>

// 12.	POSCHITAT' KOL-VO MAX ELEMENTOV V POSLEDOVATEL'NOSTI CHISEL

using namespace std;

int main()
{	
	int n;
	cout << "Enter kolichestvo chisel : ";
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int number;
		cout << "Enter number: ";
		cin >> number;
		v.push_back(number);
	}
	int counter = 0;
	int min = INT_MIN;
	for (auto i : v) {
		if (i > min) { min = i; }
	}
	for (auto i : v) {
		if ( i == min) { counter++; }
	}
	cout << "Kol-vo max elementov = " << counter;
	return 0;
}
