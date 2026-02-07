#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* This function will run in a thread */
void *worker(void *age) {
	printf("Thread: started\n");
	sleep(2);
	printf("Thread: finished\n");
	return NULL;
}

int main() {
	pthread_t tid;

	printf("Main: creating thread\n");

	pthread_create(&tid, NULL, worker, NULL);

	printf("Main: waiting for thread\n");

	pthread_join(tid, NULL);

	printf("Main: thread finished, exiting\n");

	return 0;
}

