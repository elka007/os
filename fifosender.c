#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int fd;
char *myfifo1="/tmp/myfifo1";
mkfifo(myfifo1,0666);
char arr1[80],arr2[80];
while(1)
{
fd=open(myfifo1,O_WRONLY);
fgets(arr2,80,stdin);
write(fd,arr2,strlen(arr2)+1);
close(fd);
fd=open(myfifo1,O_RDONLY);
read(fd,arr1,sizeof(arr1));
printf("User2: %s\n",arr1);
close(fd);
}
return 0;
}
