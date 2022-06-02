flag_ldr: flag_ldr.S
	gcc -m32 -c flag_ldr.S -o flag_ldr.o
	gcc -m32 flag_ldr.o -o flag_ldr.exe
	objcopy -S -O binary -j .text flag_ldr.o flag_ldr.bin
