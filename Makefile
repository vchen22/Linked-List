EXE = test
OBJS = main.o
LIBS = -lmemwrap

ifeq ($(DEBUG), 1)
CFLAGS = -O0 -g --std=gnu99 -L.
else
CFLAGS = -O0 --std=gnu99 -L.
endif

.PHONY: clean

$(EXE): $(OBJS) libmemwrap.a
	gcc -Wall -Wextra -o $@ $(CFLAGS) $(OBJS) $(LIBS)

libmemwrap.a : memwrap.o memwrap.h
	ar rcs libmemwrap.a memwrap.o

no_warnings: $(OBJS) libmemwrap.a
	gcc -o $(EXE) $(CFLAGS) $(OBJS) $(LIBS)

clean :
	rm libmemwrap.a
	rm *.o
	rm $(EXE)

