#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,i,b[20],w[20],t[20];
float aw,at;
printf("enter no of processes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter bust time for process %d",i+1);
scanf("%d",&b[i]);
}
w[0]=0;
for(i=0;i<n;i++)
{
w[i+1]=w[i]+b[i];
t[i]=w[i]+b[i];
}
printf("process busttime wating tat\n");
for(i=0;i<n;i++)
{
printf(" p%d %d %d %d\n",i,b[i],w[i],t[i]);
}
for(i=0;i<n;i++)
{
aw+=w[i];
at+=t[i];
}
aw=aw/n;
at=at/n;
printf("avg wating time is %f\n",aw);
printf("avg tat time is %f\n",at);
return 0;
}
