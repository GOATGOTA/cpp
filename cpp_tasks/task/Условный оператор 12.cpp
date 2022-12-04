// 4.12 min из 3-ёх чисел 

# include <iostream>
# include <stdio.h>

using namespace std;


int main ()
{
	setlocale(LC_ALL, "Russian");
	
	double i1,i2,i3;
	
	cin>>i1>>i2>>i3;
	
	
	if ((i1 <= i2) &  (i1 <= i3)){
		cout << i1;
	} else if ((i2<=i1) & (i2<=i3)){
		cout << i2;
	} else {
		cout << i3;
	}
	
	return 0;
	
}

