#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

sem_t mutex, wrt;
int sharedvar=99;
pthread_t writers[5], readers[5];
int readercount=0;

void reader(){
	sem_wait(&mutex);
	readercount++;
	if(readercount==1)
		sem_wait(&wrt);
	sem_post(&mutex);
	printf("\n%d reader is reading sharedvar=%d",readercount, sharedvar);
	printf("\nReader is done");
	sem_wait(&mutex);
	readercount--;
	if(readercount==0)
		sem_post(&wrt);
	sem_post(&mutex);
}

void writer() {
	printf("\nWriter is trying to enter");
	sem_wait(&wrt);
	printf("\nWriter has entered CS");
	sharedvar++;
	printf("\n Writer has changed value of shared variable to %d", sharedvar);
	sem_post(&wrt);
	printf("\n Writer is out of  CS");

}

int main(){
	int n2, i;
	printf("Enter no. of reader and writer");
	scanf("%d",&n2);
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	for(i=0;i<n2;i++){
		pthread_create(&writers[i],NULL,(void *)writer,NULL);
		pthread_create(&readers[i],NULL,(void *)writer,NULL);
	}

	for(i=0;i<n2;i++){
		pthread_join(writers[i],NULL);
		pthread_join(readers[i],NULL);
	}
}
/*
Enter no. of reader and writer2

Writer is trying to enter
Writer has entered CS
 Writer has changed value of shared variable to 100
 Writer is out of  CS
Writer is trying to enter
Writer has entered CS
 Writer has changed value of shared variable to 101
 Writer is out of  CS
Writer is trying to enter
Writer has entered CS
 Writer has changed value of shared variable to 102
 Writer is out of  CS
Writer is trying to enter
Writer has entered CS
 Writer has changed value of shared variable to 103
 Writer is out of  CS%
 */