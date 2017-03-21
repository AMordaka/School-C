#ifndef STOS_H
#define STOS_H

using namespace std;

class stack
{
public:
	stack();
	~stack();
	void clear();
	void push(int val);
	int pop();
	bool isEmpty();	

private:
	int size; 
	int rozmiar_stosu;
	int *elements;
	void init();
};


#endif
