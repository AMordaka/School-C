#ifndef STOS_H
#define STOS_H

#include <stdbool.h>

typedef struct {
    int size;
    int rozmiar_stosu;
    int *elements;
} stack;


void init(stack* S);
void push(stack *S, int element);
void destroy(stack* S);
int pop (stack* S);
void clear (stack* S);
bool isEmpty(stack* S);


#endif
