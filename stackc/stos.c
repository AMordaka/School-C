#include "stos.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define ROZMIAR 5
#define MNOZNIK 2


void init(stack* S)
{
	S->rozmiar_stosu = ROZMIAR; 
	S->elements = (int*)malloc((S->rozmiar_stosu) * sizeof(int));
	assert(S->elements);
    S->size = -1;
}


void push(stack *S, int element)
{
 
 
   if(S->size == (S->rozmiar_stosu - ROZMIAR)) 
	{
        int *tmp = (int*) realloc(S->elements, sizeof(int) * S->rozmiar_stosu * MNOZNIK);
        assert(tmp) ;
		
		S->elements = tmp;
        S->rozmiar_stosu = S->rozmiar_stosu * MNOZNIK;
    
    }
    S->size++;
    S->elements[S->size] = element;
}

int pop(stack *S)
{
	int top;
	if(S->size == -1) 
	{
        abort();
    } 
	else 
	{
        top = S->elements[S->size];
        S->size--;
    }
    
    return top;
}


void destroy(stack *S)
{
	free(S->elements);
}

bool isEmpty(stack* S)
{
    if(S->size == -1)
    {
        return true;
    }
    else 
        return false;
    
}

void clear(stack* S)
{
destroy(S);
init(S);
}