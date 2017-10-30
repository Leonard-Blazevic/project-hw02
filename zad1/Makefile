FUNCSRC=$(wildcard src/Func/*c )
TESTSRC=$(wildcard src/Test/*c )

FUNCOBJ=$(patsubst %c, %o, $(FUNCSRC))
TESTOBJ=$(patsubst %c, %o, $(TESTSRC))

EXE=$(addprefix exe/, $(notdir $(patsubst %c, %elf, $(TESTSRC))))

MAKE=make

.SECONDARY:

all: $(EXE)
	@for exe in $(EXE) ;\
	do \
		./$$exe ; \
	done

exe/%.elf: src/Test/%.o $(FUNCOBJ)
	gcc $< $(FUNCOBJ) -lm -o $@

%.o: %.c
	gcc -c $< -I inc/ -lm -lfftw3 -o $@

clean:
	rm -f $(FUNCOBJ) $(TESTOBJ) $(EXE)
