
#include "emulator.h"

#include <stdlib.h>

char* ram;
long int ram_size = 0;
int start(long int size)
{
	ram_size = size;
	ram = (char*) malloc(ram_size * sizeof(char));
	return 0;
}

int emulate(char* code, long int code_size)
{
	char argument;
	char instruction;
	for(int ic = 0/*instruction counter*/; ic < code_size; ic++)
	{
		instruction = code[ic];
		/*
		if(argumented(instruction))
		{
			argument = ++ic;
		}
		*/
	
	}
	
	
	
	return 0;
}
