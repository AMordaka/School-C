#include <iostream>
#include "complex.h"
using namespace std;

int main()
{

	Complex a(3.0, 1.0);
	Complex b(1.0, 1.0);
	Complex c(1.0, 3.0);
	Complex d;
	

	d = a + c;
	cout<<"Dodawanie: a + c   "<<d<<endl;
	d = a - c;
	cout<<"Odejmowanie a - c: "<<d<<endl;
	d = a * c;
	cout<<"Mnozenie a * c     "<<d<<endl;
	d = 10 * c;
	cout<<"Mnozenie 10 * c    "<<d<<endl;
	d = c * 10;
	cout<<"Mnozenie c * 10    "<<d<<endl;
	d = 2/c;
	cout<<"Dzielenie 2 / c    "<<d<<endl;
	a += b += c;
	cout<<"Dodawanie a+b+c    "<<a<<endl;
	
	return 0;
}
