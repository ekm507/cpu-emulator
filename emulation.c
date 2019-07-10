
#include "emulation.h"

#include <stdlib.h>

//dynamic memory for storing variables
short int* ram;
long int ram_size = 0;

//register memory

//const int reg_size = 8;
//short int reg[reg_size];

struct register_struct
{
	int DR;
	int AR;
	int AC;
	int IR;
	int PC;
	int TR;
	int INPR;
	int OUTR;

}reg;


//initialize the emulator
int initialize_emulator(long int size)
{
	ram_size = size;
	ram = (short int*) malloc(ram_size * sizeof(short int));
	return 0;
}


//start emulation
int emulate(short int* code, long int code_size)
{
	short int argument;
	short int instruction;
	
	//hh = first 4 bits of instruction
	char hh = (instruction & 0xf000) >> 12;
	
	for(reg.PC = 0/*instruction counter*/; reg.PC < code_size; reg.PC++)
	{
		instruction = code[reg.PC];
		
		
		//see if instruction does not have arguments.
		if(hh == 0x7 || hh == 0xf)
		{
		
			//execute the instruction
			switch(instruction)
			{
				//CLA
				case 0x7800 :
					//clear AC register
					reg.AC = 0;
					break;
					
				//CLE
				case 0x7400:
					//clear E TODO
					break;
				
				//CMA
				case 0x7200:
					//compliment AC register
					reg.AC ^= 0xffff;
				
				//CME
				case 0x7100:
				
					break;
			
				
				//COR
				case 0x7080:
				
					break;
					
				//CIL
				case 0x7040:
				
					break;
					
				//INC
				case 0x7020:
					//increase AC register by 1.
					reg.AC++;	
					break;
					
				//SPA
				case 0x7010:
					//pass next instruction if AC register > 0
					if(reg.AC > 0)
						reg.PC++;
					break;
					
				//SNA
				case 0x7008:
				
					break;
			
				//SZA
				case 0x7004:
					//pass next instruction if AC register is 0.
					if(reg.AC == 0)
						reg.PC++;
				
					break;
			
				//SZE
				case 0x7002:
				
					break;
			
				//HLT
				case 0x7001:
					//halt the computer
					return 0;
					break;
			
			}
		
		}
		
		//wait for each clock to let emulation look real
		//TODO
		
	}
	
	
	
	return 0;
}


