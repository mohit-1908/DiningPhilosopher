#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "monitor.h"


void *phil(void *i)
{
	while(1)
	{
		int philNum = *(int *) i;
		int j,k;
		j = rand();
		j = j % 11;
		printf("\nPhilosopher number '%d' is thinking for %d secs",philNum,j);
		sleep(j);
		pick_fork(philNum);
		k = rand();
		k = k % 4;
		printf("\nPhilosopher number '%d' is eating for %d secs",philNum,k);
		sleep(k);
		put_fork(philNum);
	}

}

int main()
{
	int i, loc[N];
	pthread_t threads[N];
	pthread_attr_t at;

	initialization();

	pthread_attr_init(&at);

	for (i = 0; i < N; i++) 
	{
		loc[i] = i;
		pthread_create(&threads[i], NULL,phil, (int *) &loc[i]);
	}
	for (i = 0; i < N; i++)
	{
		pthread_join(threads[i], NULL);
	}

	return 0;
}
