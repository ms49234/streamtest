CC = g++
CXX = g++
CFLAGS = -O2
CXXFLAGS = $(CFLAGS)
INCLUDES =
LIBS = -pthread -lstdc++
OBJS = main.o core0.o core1.o core2.o core3.o

SMPSGLIB = "$(STREAMIT_HOME)/library/smpsg"
INCLUDES += -I$(SMPSGLIB)

all: libVectorDist_sgate_entry.a

libVectorDist_sgate_entry.a: $(OBJS)
	ar rs $@ $^


clean:
	rm -f *.o *.a VectorDist

main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o main.o main.c

core0.o: core0.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o core0.o core0.c

core1.o: core1.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o core1.o core1.c

core2.o: core2.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o core2.o core2.c

core3.o: core3.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o core3.o core3.c

