#include <iostream>
#include "assocjacyjna.h"

int main() 
{
	asoctab a1,a2;
	a1["ala"] = 1;
	a1["ola"] = 2;
	a1["Ola"] = 3;

	std::cout<<a1["ola"];
	std::cout<<a1["Ola"];
	std::cout<<a1["o"];
	std::cout<<"\n";
	std::cout<<"\n";
	
	asoctabnowa b1,b2;
	b1["tom"] = 1;
	b2["kom"] = 2;

	std::cout<<b1["toM"];
	std::cout<<b1["Tom"];
	std::cout<<b2["KOM"];
	
	return 0;
}
