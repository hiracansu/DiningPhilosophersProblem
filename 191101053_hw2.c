#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int k, N, lower, upper, k_temp;
sem_t mutex;
sem_t mutex_a;

sem_t *S;                       
sem_t *SA;      
int (*state)[3];          
pthread_t *thread_id;

#define EMPTY 6
#define FULL 5
#define WANTJUG 4
#define TAKEJUG 3
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + N-1) % N
#define RIGHT (phnum + 1) % N

//--------------------------------------------------eating-------------------------------------------------------------------

void randomButterMilkNumber(int lower, int upper){
    srand(time(0));
    printf("Garson %d tas ayran koydu.\n",k_temp);

    for(int i=0; i<N; i++) {
		printf("Philosopher %d -> %d tas ayran içti\n",i+1 , state[i][2]);
    }
    for(int i=0; i<N; i++) {
		state[i][2] = 0;
    }
    k = (rand() % (upper - lower + 1)) + lower;
	k_temp = k;
    sleep(5);
}

void test(int phnum) {
	if (state[phnum][0] == HUNGRY && state[phnum][1] == FULL && state[LEFT][0] != EATING && state[RIGHT][0] != EATING ) {
		state[phnum][0] = EATING;
        state[phnum][1] = EMPTY;
        state[phnum][2] = state[phnum][2]+1;
		//printf("    	Philosopher %d cubuklari aldi %d and %d EATING\n",	phnum + 1, LEFT + 1, phnum + 1);
        k--;
        if(k == 0)
            randomButterMilkNumber(lower,upper);
		sem_post(&S[phnum]);
	}
}

void take_fork(int phnum) {
	sem_wait(&mutex);
	state[phnum][0] = HUNGRY;
	//printf("    Philosopher %d HUNGRY\n", phnum + 1);
	test(phnum);
	sem_post(&mutex);
	sem_wait(&S[phnum]);
}

void put_fork(int phnum){
	sem_wait(&mutex);
	state[phnum][0] = THINKING;
	//printf("			Philosopher %d cubuklari birakti %d and %d THINKING\n", phnum + 1, LEFT + 1, phnum + 1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}


//------------------------------------------------------drinking---------------------------------------------------------


void test_jug(int phnum) {
    int jug_take = 0;
    for(int i = 0 ; i< N; i++){
        if(state[i][0] == TAKEJUG && phnum != i){
            jug_take = 1;
        }
    }
	if (state[phnum][0] == WANTJUG && state[phnum][1] == EMPTY && jug_take != 1) {
		state[phnum][0] = TAKEJUG;
        state[phnum][1] = FULL;
		//printf("	Philosopher %d surahi aldi, ayran dolduruyor \n",	phnum + 1);
		sem_post(&SA[phnum]);
	}
}

void take_jug(int phnum) {
	sem_wait(&mutex_a);
	state[phnum][1] = EMPTY;
	state[phnum][0] = WANTJUG ;
	//printf("	Philosopher %d ayran doldurmak istiyor\n", phnum + 1);
	test_jug(phnum);
	sem_post(&mutex_a);
	sem_wait(&SA[phnum]);
}

void put_jug(int phnum){
	sem_wait(&mutex_a);
	state[phnum][0] = THINKING;
	//printf("	Philosopher %d surahi birakti ve THINKING \n ",phnum + 1);
	for(int i = 0 ; i< N; i++){
		if(phnum != i)
			test_jug(i);
	}
	sem_post(&mutex_a);
}


void* philosopher(void* num){
    while (1) {
		int* i = num;
        take_fork(*i);
        put_fork(*i);
        take_jug(*i);
        put_jug(*i);
    }
}

int main(int argc, char *argv[]){
    N = atoi(argv[1]);
    int phil[N];
    lower = 1;
    upper = 5 * N;
    k = (rand() % (upper - lower + 1)) + lower;
	k_temp = k;

	S = malloc(N*sizeof(sem_t));
	SA = malloc(N*sizeof(sem_t));
	thread_id = malloc(N*sizeof(pthread_t));
	state = malloc(sizeof(*state) * N);


	sem_init(&mutex,0,1);
	
	for(int i=0; i<N; i++)
		sem_init(&S[i], 0, 0);

	sem_init(&mutex_a,0,1);
	
	for(int i=0; i<N; i++)
		sem_init(&SA[i], 0, 0);


	for(int i=0; i<N; i++) {
		phil[i]=i;
        state[i][1] = FULL;
		pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }
    for(int i=0; i<N; i++) {
	    pthread_join(thread_id[i],NULL);
    }
}
