CFLAGS		+= -O0 -fno-stack-protector -m32 -fverbose-asm -march=i386
LDFLAGS		+= 
DISFLAGS	+= --source --section=.text
SOURCES		:= $(wildcard *.c)
PROGRAMS	:= $(patsubst %.c,%,$(SOURCES))

%: %.c
	$(CC) $(CFLAGS) -S $< -o $*.s
	$(CC) $*.s -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $*.S
	execstack -s $@

all: $(PROGRAMS)

clean:
	- find . -executable -type f -delete
	- rm -f *.s *.S core

example1 example2 example3 shellcode shellcodeasm2: CFLAGS += -ggdb
exit overflow1 shellcode shellcodeasm shellcodeasm2: CFLAGS += -static
