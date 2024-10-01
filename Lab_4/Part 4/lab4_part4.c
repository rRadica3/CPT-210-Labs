#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#define NUM_ITERATIONS 100000

#define USEC_PER_SECOND		1E6
#define USEC_PER_NSEC		1E-3

int main()
{
	long   elapsed_time_usec=0;
	double overhead_per_call;
	struct timeval start_tv, end_tv;
	struct timespec start_ts, end_ts;
	
	gettimeofday(&start_tv, NULL);
	
	for (int i=0; i<NUM_ITERATIONS; ++i)
	{
		read(STDIN_FILENO, NULL, 0);
	}
	
	gettimeofday(&end_tv, NULL);
	
	elapsed_time_usec= ((end_tv.tv_sec - start_tv.tv_sec) * USEC_PER_SECOND+
					   (end_tv.tv_usec- start_tv.tv_usec));
	
	overhead_per_call= (double)elapsed_time_usec/ NUM_ITERATIONS;
	
	printf("Total time: %ld microseconds\n", elapsed_time_usec);
	printf("Overhead per read system call: %.6f microseconds\n", overhead_per_call);
	
	clock_gettime(CLOCK_MONOTONIC, &start_ts);
	
	for (int i=0; i<NUM_ITERATIONS; ++i)
	{
		read (STDIN_FILENO, NULL, 0);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end_ts);
	
	elapsed_time_usec= ((end_ts.tv_sec- start_ts.tv_sec)* USEC_PER_SECOND+
						(end_ts.tv_nsec- start_ts.tv_nsec)*USEC_PER_NSEC);
						
	overhead_per_call= (double)elapsed_time_usec/ NUM_ITERATIONS;
	
	printf("Total time: %ld microseconds\n", elapsed_time_usec);
	printf("Overhead per read system call: %.6f microseconds\n", overhead_per_call);
	
	return 0;
}
	
