#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunction(void* args)
{
     for(int i=0;i<5;i++)
     {
        printf("I am thread one Function.\n");

        sleep(1);
     }
}
void* threadFunction1(void* args)
{
     for(int i=0;i<5;i++)
     {
        printf("I am thread two Function\n");

        sleep(3);
     }
}
int main()
{
    pthread_t id1,id2;
    int ret;

    ret=pthread_create(&id1,NULL,&threadFunction,NULL);
    ret=pthread_create(&id2,NULL,&threadFunction1,NULL);
          printf("Thread created successfully.\n");

   pthread_join(id1,NULL);
   pthread_join(id2,NULL);
   for(int i=0;i<3;i++)
   {
	printf("I am main thread\n");
	sleep(2);
   }
   return 0;
}   
