
CXX = g++
CXXFLAGS = -O2

SMPLIB_DIR = "$(STREAMIT_HOME)/library/smpsg"
SMPLIB = smpsg

STREAMIT_DIR = ./dstreamit

STREAMIT_FILE = VectorDist
STREAMIT_LIB = VectorDist_sgate_entry

all: stream_gate_host

clean:
	rm -f *.o stream_gate_host
	make -C $(STREAMIT_DIR) -f Makefile.streamit clean

stream_gate_host: stream_gate_host.o $(STREAMIT_DIR)/lib$(STREAMIT_LIB).a
	$(CXX) $(CXXFLAGS) -L$(SMPLIB_DIR) -o $@ $^ -pthread -lsmpsg

stream_gate_host.o: stream_gate_host.cpp $(STREAMIT_DIR)/lib$(STREAMIT_LIB).a

$(STREAMIT_DIR)/lib$(STREAMIT_LIB).a: $(STREAMIT_DIR)/$(STREAMIT_FILE).str
	make -C $(STREAMIT_DIR) -f Makefile.streamit

test:
	./test.sh

test_k:
	make -C $(STREAMIT_DIR) -f Makefile.streamit clean
	make -C $(STREAMIT_DIR) -f Makefile.streamit test
	
