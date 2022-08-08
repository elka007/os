#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,b[10],w[10],t[10],i,h[10],temp=0,th=0,j;
float aw=0,at=0;
printf("enter number of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the bust time of p%d\n",i);
scanf("%d",&b[i]);
h[i]=i;
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
th=h[i];
h[i]=h[j];
h[j]=th;
}
}
}
w[0]=0;
printf("process bust time wating time turn aroundtime\n");
for(i=0;i<n;i++)
{
w[i+1]=w[i]+b[i];
t[i]=b[i]+w[i];
printf("p%d %d %d %d\n",h[i],b[i],w[i],t[i]);
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
