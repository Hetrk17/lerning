#include<stdio.h>
#include<stdlib.h>
extern int EF_PROTECT_BELOW;


void buggy()
{
	int *intptr;
	int i;
	intptr = (int *)malloc(sizeof(int));
	//printf("Malloc checking : Addr = %08x and Size =%d\n",intptr,sizeof(int)*10);
	
	*intptr = 100;
	printf("value at ptr intptr = %d\n", (*intptr));
	free(intptr);
	*intptr = 99;
	printf("value at ptr intptr = %d\n", (*intptr));
}

int main()
{
	buggy();
	return 0;
}
