#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
int i;
void*shared_memory;
char buff[100];
int shmid;
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
shared_memory=shmat(shmid,NULL,0);
printf("Process attacted at %p\n",shared_memory);
printf("Data read from the shared memory is :%s\n",(char
*)shared_memory);
}
