FUNCSRC=$(wildcard src/func/*c )
TESTSRC=$(wildcard src/test/*c )

FUNCOBJ=$(patsubst %c, %o, $(FUNCSRC))
TESTOBJ=$(patsubst %c, %o, $(TESTSRC))

INC=inc/

EXE=$(patsubst %c, %elf, $(TESTSRC))

MAKE=make

.SECONDARY:

all: $(EXE)
	@for exe in $(EXE) ;\
	do \
		./$$exe ; \
	done

%.elf: %.o $(FUNCOBJ)
	gcc $(FUNCOBJ) $< -lm -o $@

%.o: %.c
	gcc -c $< -I inc/ -lm -lfftw3 -o $@

clean:
	rm -f $(FUNCOBJ) $(TESTOBJ $(EXE)

