# Names of the executables we want to generate
PROGS = driver

# Intermediate object files that we want to clean up
OBJS = quadratic_c.o quadratic_a.o \
        sum_array_c.o sum_array_a.o \
        find_max_c.o find_max_a.o \
	fib_iter_c.o fib_iter_a.o \
	fib_rec_c.o fib_rec_a.o \
	strlen_c.o strlen_a.o

# Any special flags we want to give to gcc during compilation
CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${FLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

driver: driver.c\
	quadratic_c.o quadratic_a.o \
	sum_array_c.o sum_array_a.o \
	find_max_c.o find_max_a.o \
	fib_iter_c.o fib_iter_a.o \
	fib_rec_c.o fib_rec_a.o \
	strlen_c.o strlen_a.o
	gcc ${CFLAGS} -o $@ $^

clean:
	rm -rf ${PROGS} ${OBJS}
