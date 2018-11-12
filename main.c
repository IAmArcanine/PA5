#include "pa5.h"
#define RANGE 10000
int main(int argc, char *argv[]){
	int n         = 0;
	int p = 0;
	int in = 0;
	if (argc < 3){
		printUsage();
		return 0;
	}
	//first arg is n, second is #of threads
	n         = atoi(argv[1]);
	p = atoi(argv[2]);

	omp_set_num_threads(p);

	//1) Throw n darts
	double time = omp_get_wtime();

	#pragma omp parallel for shared(n) reduction(+:in)
	for (int i = 0; i < n; i++){
		int rank = omp_get_thread_num();
	// generate rand x and y between 0 and 1
		double x = (double)(rand() %RANGE)/RANGE;
		double y = (double)(rand() %RANGE)/RANGE;
		if (isInCircle(x, y)){
			//printf("in\n");
			in++;
		}
		//else printf("out\n");
		//printf("thread[%d] has i: %d, in: %d\n", rank, i, in);
	}
	printf("after loop: n = %d\n", in);
	//2) what fraction of time did the darts land in teh circle
	//printf("in: %d, total: %d\n",in, n);
	double frac = (double)in/(double)n;
	//Prob(dart lands in circle is area(circ)/area(squard)
	//= πr^2 / 4r^2 = π/4
	//3) π ~ 4 * Prob
	double pi_aprx = frac * 4.0;
	time = omp_get_wtime() - time;

	printf("π = %f\n#threads: %d, time: %f seconds\n", pi_aprx, p, time);
	return 0;
}
