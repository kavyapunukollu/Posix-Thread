#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
void *thread_function(void *args)
{
	
	printf("I am thread function\n");
	sleep(5);

}
void *thread_function2(void *args)
{

        printf("I am thread 2 function\n");
        sleep(10);

}

int main()
{
	pthread_t t_id,t_id2;
	int ret,args=1;
	printf("process id=%d\n",getpid());  

	printf("before creation of thread\n");

	//creating a thread
	ret=pthread_create(&t_id,NULL,thread_function,NULL);
	ret=pthread_create(&t_id2,NULL,thread_function2,NULL);
	if(ret==0)
		printf("thread created succes\n");
	else
		printf("problem in creating thred");

	//waiting for the created thread to terminate
	pthread_join(t_id,NULL);
	pthread_join(t_id2,NULL);
	printf("thread terminate\n");  
	return 0;

}



















