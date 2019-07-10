emulator: main.o emulation.o
	gcc main.o emulation.o -o emulator

main.o: main.c
	gcc -c main.c

emulator.o: emulation.c emulation.h
	gcc -c emulation.c

clean:
	rm *.o emulator
	
play:
	gcc play.c -o play
