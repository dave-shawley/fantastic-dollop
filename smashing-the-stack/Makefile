CFLAGS += -O0 -fno-stack-protector -m32 -fverbose-asm -march=i386
LDFLAGS += 
DISFLAGS += --source --section=.text

PROGRAMS := example1 example2 example3 exit shellcode shellcodeasm shellcodeasm2 testsc testsc2

%: %.c
	$(CC) $(CFLAGS) -ggdb -S $< -o $*.s
	$(CC) $*.s -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $*.S

all: $(PROGRAMS)

clean:
	- rm -f *.s *.S $(PROGRAMS)

exit: exit.c
	$(CC) $(CFLAGS) -static $< -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $@.S

shellcode: shellcode.c
	$(CC) $(CFLAGS) -ggdb -static $< -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $@.S

shellcodeasm: shellcodeasm.c
	$(CC) $(CFLAGS) -ggdb -static $< -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $@.S

shellcodeasm2: shellcodeasm2.c
	$(CC) $(CFLAGS) -ggdb -static $< -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $@.S

testsc: testsc.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
	execstack -s $@
	objdump --disassemble $(DISFLAGS) $@ > $@.S

testsc2: testsc2.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
	execstack -s $@
	objdump --disassemble $(DISFLAGS) $@ > $@.S
