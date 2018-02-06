#include <cstdio>

#include "./dstreamit/VectorDist_sgate_entry.h"

#define NUM_ITEMS 16777216
#define BUFF_SIZE 4096

using namespace std;

float *x_y, *res, *in_buff, *out_buff;

void fillBuffer(int offset){
    for(int i = 0; i < BUFF_SIZE * 2; i++) {
        in_buff[i] = x_y[offset * BUFF_SIZE * 2 + i];
    }

    VectorDist_sgate_assign_memr_in_buff(in_buff, BUFF_SIZE*2);
	VectorDist_sgate_assign_memw_out_buff(out_buff, BUFF_SIZE);
}

void processBuffer(int offset){
    for(int i = 0; i < BUFF_SIZE; i++) {
        res[offset * BUFF_SIZE + i] = out_buff[i];
    }
}

int main () {
    int br = 0;

	x_y = new float [NUM_ITEMS * 2];
	res = new float [NUM_ITEMS];

	in_buff = new float [BUFF_SIZE*2];
	out_buff = new float [BUFF_SIZE];
/*
	for(int i = 0; i < SIZE; i++) {
	        x[i] = x[i-1] + 0.325;
        	y[i] = y[i-1] + 0.042;

		x_y[2*i] = x[i];
		x_y[2*i+1] = y[i];
	}
*/

	for(int i = 0; i < NUM_ITEMS; i++) {
		x_y[2*i] = x_y[2*(i-1)] + 3.25;
		x_y[2*i+1] = x_y[2*i-1] + 0.42;
		//res[i] = 0;
	}

	int st = VectorDist_sgate_init();

//for ( int j = 0; j < 5; j++) {
	for ( int i = 0; i < NUM_ITEMS / BUFF_SIZE; i++) {
        fillBuffer(i);

		st = VectorDist_sgate_fire();
		st = VectorDist_sgate_synchronize();

		processBuffer(i);
	}
//}

	st = VectorDist_sgate_exit();
/*
	for(int i = 0; i < NUM_ITEMS; i++) {
		printf("%f\n", res[i]);
	}
*/
	delete[] x_y;
	delete[] res;
    delete[] in_buff;
    delete[] out_buff;

	return 0;
}

