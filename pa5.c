#include "pa5.h"


void printUsage(void){
	printf("pi <n> <number of threads>\n");
}

int isInCircle(double px, double py){
	// true if ( x^2 + y^2 < 0.5^2)
	double x = px-0.5, y = py -0.5;
	//printf("(%f*%f) + (%f*%f) < 0.25 ? ", x,x,y,y);
	if ( (x*x) + (y*y) < 0.25 ){
		return 1;
	}
	return 0;
}
