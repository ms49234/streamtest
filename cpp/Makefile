CXX = g++

all: VectorDist

clean:
	rm -f *.o VectorDist

VectorDist:
	$(CXX) -O0 -o VectorDist VectorDist.cpp

test: VectorDist
	./test.sh

qtest:
	./test.sh
