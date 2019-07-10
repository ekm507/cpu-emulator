/* a shell based emulator for "The 16-bit CPU"
*  main.c
*  the main file code.
*
* usage :
* ./emulator [asm code file name] -o [pre-settings file]
*/


//TODO : write line-by-line emulator
//TODO : check if file opens without errors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emulation.h"

int main(int argc, char** argv)
{
	
	
	//get code file name to emulate
	char filename[1000];
	if(argc < 2)
	{
		printf("code file name to be used:");
		scanf("%s", filename);
		
	}
	else
		strcpy(filename, argv[1]);


	//open the code file
	FILE* codefile;
	codefile = fopen(filename, "r");

	unsigned long int size;

	//get file size
	fseek(codefile, 0, SEEK_END); // seek to end of file
	//open and close the file in order to seek to the begining of the file
	size = ftell(codefile); // get current file pointer
	fclose(codefile);
	codefile = fopen(filename, "r");

	//the code will be stored here
	short int *code;
	code = malloc(size * sizeof(short int));

	unsigned long int i = 0;

	//load the code file into memory
	while(!feof(codefile))
		code[++i] = fgetc(codefile);

	//close the code file
	fclose(codefile);
	
	//size of the dynamic memory
	long int ram_size = 4096;
	
	initialize_emulator(ram_size);

	//start emulation
	int status = -1;
	status = emulate(code, i);
	
	return 0;
}

