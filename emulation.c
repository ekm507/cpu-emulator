
#include "emulation.h"

#include <stdlib.h>

//dynamic memory for storing variables
short int* ram;
long int ram_size = 0;

//register memory
const int reg_size = 8;
short int reg[reg_size];


//initialize the emulator
int initialize_emulator(long int size)
{
	ram_size = size;
	ram = (short int*) malloc(ram_size * sizeof(short int));
	return 0;
}


//start emulation
int emulate(char* code, long int code_size)
{
	short int argument;
	short int instruction;
	
	//hh = first 4 bits of instruction
	char hh = (instruction & 0xf000) >> 12;
	
	for(int pc = 0/*instruction counter*/; pc < code_size; pc++)
	{
		instruction = code[pc];
		
		
		
		if(hh == 0x7 || hh == 0xf)
		
	}
	
	
	
	return 0;
}
