# Names of the executables we want to generate
PROGS = max_main max3_main count_zeros_main smult_main nbits_main

# Intermediate object files that we want to clean up
OBJS = max_c.o max_a.o max3_c.o max3_a.o \
       count_zeros_c.o count_zeros_a.o \
       smult_c.o smult_a.o \
       nbits_c.o nbits_a.o

# Any special flags we want to give to gcc during compilation
CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${FLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

max_main : max_main.c max_c.o max_a.o
	gcc ${CFLAGS} -o $@ $^

max3_main : max3_main.c max3_c.o max3_a.o
	gcc ${CFLAGS} -o $@ $^

count_zeros_main : count_zeros_main.c count_zeros_c.o count_zeros_a.o
	gcc ${CFLAGS} -o $@ $^

smult_main : smult_main.c smult_c.o smult_a.o
	gcc ${CFLAGS} -o $@ $^

nbits_main : nbits_main.c nbits_c.o nbits_a.o
	gcc ${CFLAGS} -o $@ $^

clean:
	rm -rf ${PROGS} ${OBJS}

