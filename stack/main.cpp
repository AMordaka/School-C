#include <iostream>
#include "stos.h"

using namespace std;

int main()
{
	int i,zm;
	
	stack stos;
	stack stos1;
	stack stos2;
	stack stos3;
	stack stos5;
	
	for(i = 0; i < 52; i++)
	{
		stos.push(i);
	}
	
	stos.clear();
	zm = stos.isEmpty();
	cout << zm << endl;
	
	
	return 0;
}

