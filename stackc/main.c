#include <stdio.h>
#include "stos.h"


int main()
{
    
    stack zmienna;
    stack *stos = &zmienna;

	init(stos);
    int i;
    for(i=12; i < 43; i++)
	{
		push(stos,i);
	}
	clear(stos);

	printf("\n%d\n",isEmpty(stos));
	destroy(stos);



    return 0;
}

