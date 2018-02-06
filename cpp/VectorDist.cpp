#include<cstdio>
#define NUM_ITEMS 131072

using namespace std;

float *x_y, *res;

int main () {
	x_y = new float[NUM_ITEMS * 2];
	res = new float[NUM_ITEMS];
/*
	double x[SIZE];
	double y[SIZE];

	for(int i = 0; i < SIZE; i++) {
	        x[i] = x[i-1] + 3.25;
        	y[i] = y[i-1] + 0.42;
		
		x_y[2*i] = x[i];
		x_y[2*i+1] = y[i];
	}
*/	


	for(int i = 0; i < NUM_ITEMS; i++) {	
		x_y[2*i] = x_y[2*(i-1)] + 3.25;
		x_y[2*i+1] = x_y[2*i-1] + 0.42;
	}

for(int j = 0; j < 128; j++) {
	for(int i = 0; i < NUM_ITEMS; i++) {
	        res[i] = (x_y[2*i] - x_y[2*i+1]) * (x_y[2*i] - x_y[2*i+1]);
	}

}
/*
	for(int i = 0; i < NUM_ITEMS; i++) {
		printf("%f\n", res[i]);
	}
*/
	delete[] x_y;
	delete[] res;

	return 0;
}

