// 5.12 

# include <iostream>
# include <stdio.h>
# include <math.h>

using namespace std;


int main ()
{
	setlocale(LC_ALL, "Russian");
	int x;
	float value, r, d, l, s;
	
	cout << "Введите номер переменной: ";
	cin >> x;
	
	cout << "Введите значение переменной: ";
	cin >> value;
	
	switch (x){
		
		case 1:	
			r= value;
			d = 2 * r;
			l = 2 * 3.14 * r;
			s=3.14*r*r;
			printf("%f %f %f\n",d,l,s);
			break;
		case 2:
			r=x/2;
	        d=x;
	        l=2*3.14*r;
	        s=3.14*r*r;
	        printf("%f %f %f\n",r,l,s);
	        break;
	    case 3:
	        r=x/2*3.14;
	        d=2*r;
	        l=x;
	        s=3.14*r*r;
	        printf("%f %f %f\n",r,d,s);
	        break;
   		case 4:
	        r=sqrt(x/3.14);
	        d=2*r;
	        l=2*3.14*r;
	        s=x;
	        printf("%f %f %f\n",r,d,l);
	        break;
   }
	
	
}
