NUM_THREADS = 0 1 2 3 4 5 6 7 8 9 10 11 12

.PHONY: all VectorDist clean clean2

all: VectorDist

VectorDist:
	strc VectorDist.str -o VectorDist

clean2: 
	rm -fr *.h *.c *.cpp *.gph *.txt *.java *.o *.a Makefile.cluster *.png *.eps

clean: 
	rm -fr *.dot *.h *.c *.cpp *.gph *.txt *.java *.o VectorDist *.a Makefile.cluster *.png *.eps

test:
	echo "---------------------testovi StreamIt------------------" > ../teststreamit.txt
	$(foreach NUM, $(NUM_THREADS), strc -cluster $(NUM) VectorDist.str -o VectorDist;echo "----------------test${NUM}-------------" >> ../teststreamit.txt;./test.sh;)
