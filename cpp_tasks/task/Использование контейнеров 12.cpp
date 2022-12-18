#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>


using namespace std;


int main()
{

	string s = "1 0 0 0 0 1 1";
	stringstream ss(s);
	vector<int> v;

	copy(istream_iterator<int>(ss), {}, back_inserter(v));
	int counter = 0;
	int min = INT_MIN;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > min) { min = v[i]; }
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == min) { counter++; }
	}
	cout << counter;
	return 0;

}