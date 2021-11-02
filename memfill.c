#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) 
{
	char* memptr;
	int i;

	int initial_delay = argc < 2 ? 0 : atoi(argv[1]);
	int allocation_size = argc < 3 ? 256*1024*1024 : atoi(argv[2])*1024*1024;
	int num_realloc = argc < 4 ? 1 : atoi(argv[3]);
	int delay_between_realloc = argc < 5 ? 30 : atoi(argv[4]);
	int final_delay = argc < 6 ? 30 : atoi(argv[5]);

	printf("Memfill started\n");

	printf("Configuration variables:\n");
	printf("  Initial delay: %d\n", initial_delay);
	printf("  Number of reallocations: %d\n", num_realloc);
	printf("  Delay between reallocations: %d\n", delay_between_realloc);
	printf("  Final delay: %d\n", final_delay);

	printf("Waiting %d seconds\n", initial_delay);
	fflush(stdout);	
	sleep(initial_delay);

	printf("Allocating %d bytes\n", allocation_size);
	memptr = (char*)malloc(allocation_size);
	memset(memptr, 1, allocation_size);

	for (int i = 1; i <= num_realloc; i++) {
		printf("Waiting %d seconds\n", delay_between_realloc);
		fflush(stdout);
		sleep(delay_between_realloc);
		printf("Reallocating another %d bytes\n", allocation_size);
		memptr = realloc(memptr, allocation_size*(i+1));
		memset(memptr, 1, allocation_size*(i+1));
	}

	printf("Waiting %d seconds before exiting\n", final_delay);
	fflush(stdout);
	sleep(final_delay);
	printf("Memfill finished\n");
}
