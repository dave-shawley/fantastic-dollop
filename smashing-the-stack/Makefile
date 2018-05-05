CFLAGS += -O0 -fno-stack-protector -m32 -fverbose-asm
LDFLAGS += 
DISFLAGS += --source --section=.text

PROGRAMS := example1

%: %.c
	$(CC) $(CFLAGS) -ggdb -S $< -o $*.s
	$(CC) $*.s -o $@ $(LDFLAGS)
	objdump --disassemble $(DISFLAGS) $@ > $*.S

all: $(PROGRAMS)

clean:
	- rm -f *.s *.S $(PROGRAMS)
