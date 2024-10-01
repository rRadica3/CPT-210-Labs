#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define USEC_PER_SECOND     1E6
#define USEC_PER_NSEC		1E-3

long calculateSum()
{
	long sum=0;
	
	for (int i=1; i<=1000000; i++)
	{
		sum+=i;
	}
	return sum;
}
int main()
{
	long result1=0;
	long elapsed_time1_usec=0;
	long result2=0;
	long elapsed_time2_usec=0;
	
	struct timeval start_tv, end_tv;
	struct timespec start_ts, end_ts;
	
	gettimeofday (&start_tv, NULL);
	
	result1=calculateSum();
	
	gettimeofday(&end_tv, NULL);
	
	elapsed_time1_usec=((end_tv.tv_sec - start_tv.tv_sec)* USEC_PER_SECOND+
						(end_tv.tv_usec - start_tv.tv_usec));
						
	printf("Time using gettimeofday(): %ld microseconds\n", elapsed_time1_usec);
	printf("Result of calculation: %ld\n", result1);
	
	clock_gettime(CLOCK_MONOTONIC, &start_ts);
	result2=calculateSum();
	
	clock_gettime(CLOCK_MONOTONIC, &end_ts);
	
	elapsed_time2_usec= ((end_ts.tv_sec - start_ts.tv_sec) * USEC_PER_SECOND +
						(end_ts.tv_nsec - start_ts.tv_nsec) * USEC_PER_NSEC);
						
	printf("Time using clock_gettime(): %ld microseconds\n", elapsed_time2_usec);
	printf("Result of calculation: %ld\n", result2);
	
	return 0;
} 
	
	
	
