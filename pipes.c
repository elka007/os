#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define MSG_LEN 64
int main()
{
int result;
int fd[2];
char message[MSG_LEN];
char recvd_msg[MSG_LEN];
result=pipe(fd);
printf("%d\n",result);
strncpy(message,"Linux world!! ",MSG_LEN);
result=write(fd[1],message,strlen(message));
printf("%d\n",result);
if(result<0)
{
perror("write");
exit(2);
}
strncpy(message,"understanding",MSG_LEN);
result=write(fd[1],message,strlen(message));
printf("%d\n",result);
if(result<0)
{
perror("write");
exit(2);
}
strncpy(message," concepts of",MSG_LEN);
result=write(fd[1],message,strlen(message));
printf("%d\n",result);
if(result<0)
{
perror("write");
exit(2);
}
strncpy(message," pipes ",MSG_LEN);
result=write(fd[1],message,strlen(message));
printf("%d\n",result);
if(result<0)
{
perror("write");
exit(2);
}
result=read(fd[0],recvd_msg,MSG_LEN);
if(result<0)
{
perror("read");
exit(3);
}
printf("%s\n",recvd_msg);
}
