FUNCSRC=$(wildcard src/func/*c )
TESTSRC=$(wildcard src/test/*c )

TEMP1=$(notdir $(FUNCSRC))
TEMP2=$(notdir $(TESTSRC))

TEMP11=$(patsubst %c, %o, $(TEMP1))
TEMP22=$(patsubst %c, %o, $(TEMP2))

FUNCOBJ=$(addprefix exe/, $(TEMP11))
TESTOBJ=$(addprefix exe/, $(TEMP22))

INC=inc/

TEMPEXE=$(notdir $(TESTSRC))
TEMPEXE1=$(patsubst %c, %o, $(TEMPEXE))
EXE=$(addprefix exe/, $(TEMPEXE1))

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

