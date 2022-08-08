#include<stdio.h>
#include<stdlib.h>
int mutex =1,full=0,empty=3,x=0;
int main()
{
int n;
void producer();
void consumer();
int wait(int);
int signal(int);
printf("\n1.Producer \n 2.consumer \n 3.exit");
while(1)
{
printf("\n Enter your choice");
scanf("%d",&n);
switch(n)
{
case 1:
if((mutex==1)&&(empty!=0))
producer();
else
printf("\n Buffer is full");
break;
case 2:
if((mutex==1)&&(full!=0))
consumer();
else
printf("\nBuffer is empty!");
break;
case 3:
exit(0);
break;
}
}
}
int wait(int s)
{
return(--s);
}
int signal(int s)
{
return(++s);
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\n Producer produces items : %d",x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("\nConsumer consumes items : %d",x);
x--;
mutex=signal(mutex);
}
