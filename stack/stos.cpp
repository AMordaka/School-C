#include "stos.h"
#include <stdlib.h>
#include <assert.h>


#define ROZMIAR 100
#define MNOZNIK 2

using namespace std;

stack::stack()
{
	init();
}


stack::~stack()
{
	free(this->elements);
}

void stack::clear()
{
	free(this->elements);
	init();
	
}

void stack::init()
{
	rozmiar_stosu = ROZMIAR;
	elements = (int*)malloc((rozmiar_stosu) * sizeof(int));
	this -> rozmiar_stosu = rozmiar_stosu;
	size = -1;
}

void stack::push(int val)
{
	if(size == rozmiar_stosu)	
	{
		int *tmp = (int*) realloc(this->elements, sizeof(int) * this->rozmiar_stosu * MNOZNIK);
		assert(tmp) ;
	}
	
	size++;
	this->elements[size] = val;		
}


int stack::pop()
{
	int top;
	
	if(size == -1) 
	{
		abort();
	} 
	else 
	{
		top = elements[size];
		size--;
	}
	
	return top;
}
	


bool stack::isEmpty()
{
	if(size == -1)
	{
		return true;
	}
	
	return false;
}