#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <ctype.h>
#include <stdio.h>

#include "monitor.h"

int next_count = 0;
sem_t mutex;
sem_t next;

typedef struct
{
	sem_t sem;
	int count;
}cnd;
cnd x[N];

int philState[N];
int curTurn[N];

//Four integers that represent each bowl(0 and 1 are the values that can be assigned to the integers.)
int sauceBowls[4];		


void wait(int i)
{
	x[i].count++;
	if(next_count > 0)
	{
		sem_post(&next);
	}
	else
	{
		sem_post(&mutex);
	}
	sem_wait(&x[i].sem);
	x[i].count--;
}

void signal(int i)
{
	if(x[i].count > 0)
	{
		next_count++;
		sem_post(&x[i].sem);
		sem_wait(&next);
		next_count--;
	}
}
void test(int i)
{
	if(philState[i] == Hungry && philState[leftPhil] != Eating && philState[rightPhil] != Eating && curTurn[i] == i && curTurn[leftPhil] == i)
	{
		int j;
		for(j =0; j<4; j++){
			if(sauceBowls[j]==1){
				sauceBowls[j] = 0; 						//making the bowl unavailable
				break;
			}
		}
		philState[i] = Eating;							
		sauceBowls[j] = 1;								// making the bowl available again after eating.
		signal(i);
	}
}

void pick_fork(int i)
{
	sem_wait(&mutex);
	philState[i] = Hungry;
	test(i);
	while(philState[i] == Hungry)
	{
		wait(i);
	}
	if(next_count > 0)
	{
		sem_post(&next);
	}
	else
	{
		sem_post(&mutex);
	}
}

void put_fork(int i)
{

	sem_wait(&mutex);
	philState[i] = Thinking;
	curTurn[i] = rightPhil;
	curTurn[leftPhil] = leftPhil;

	test(leftPhil);
	test(rightPhil);

	if(next_count > 0)
	{
		sem_post(&next);
	}
	else
	{
		sem_post(&mutex);
	}
}

void initialization()
{
	int i;
	sem_init(&mutex,0,1);
	sem_init(&next,0,0);
	for(i = 0;i < N;i++)
	{
		philState[i] = Thinking;
		sem_init(&x[i].sem,0,0);
		x[i].count = 0;
		curTurn[i] = i;
	}
	curTurn[1] = 2;
	curTurn[3] = 4;

	for(int j=0; j<4; j++){
		sauceBowls[j] =1;			//Making all four sauceBowls available.
	}

}
