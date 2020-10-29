# Names of the executables we want to generate
PROGS = smult2_main fact_main funcs_main reverse_main

# Intermediate object files that we want to clean up
OBJS = smult2_c.o smult2_a.o fact_c.o reverse_c.o funcs_c.o fact_rec_cs_a.o

# Any special flags we want to give to gcc during compilation
CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

smult2_main : smult2_main.c smult2_c.o smult2_a.o
	gcc ${CFLAGS} -o $@ $^

fact_main : fact_main.c fact_c.o fact_a.o fact_rec_cs_a.o
	gcc ${CFLAGS} -o $@ $^

reverse_main : reverse_main.c reverse_c.o reverse_a.o
	gcc ${CFLAGS} -o $@ $^

funcs_main : funcs_main.c funcs_c.o #funcs_a.o
	gcc ${CFLAGS} -o $@ $^


test : all
	./smult2_main
	./fact_main

clean:
	rm -rf ${PROGS} ${OBJS}

