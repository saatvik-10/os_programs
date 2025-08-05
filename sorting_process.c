/*
NAME - SAATVIK MADAN
ROLL NO - 81
STATEMENT - WAP TO CREATE A CHILD PROJEXT USING FORK SYSTEM CALL. PARENT PROCESS SORTS IN ASCENDING ORDER AND CHILD PROCESS SORTS IN DESCENDING ORDER.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int arr[15];
int n;
void asc(int arr[], int n){
	for(int i=0; i<n-1;i++) {
		for(int j=0; j<n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void desc(int arr[], int n){
	for(int i=0; i<n-1;i++) {
		for(int j=0; j<n-1;j++){
			if(arr[j]<arr[j+1]){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(){ 
	pid_t num_pid;
	printf("Enter number of n ");
	scanf("%d",&n);
	
	for(int i=0; i<n;i++) {
		printf("Enter element ");
		scanf("%d",&arr[i]);
	}
	num_pid = fork();
	if (num_pid < 0){
		printf("error");
	}
	else if(num_pid == 0) {
		printf("child process id %d\n", getpid());
		asc(arr, n);
		printf("Sorted Array is\n");
		for(int i=0; i<n;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		exit(0);	
	}
	else {
		wait(NULL);
		printf("parent process id %d\n", getpid());
		desc(arr, n);
		printf("Sorted Array is\n");
		for(int i=0; i<n;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		exit(0);	
	}
}

/*
Enter number of n 4
Enter element 1
Enter element 5
Enter element 2
Enter element 6
child process id 42777
Sorted Array is
1 2 5 6 
parent process id 42760
Sorted Array is
6 5 2 1
*/