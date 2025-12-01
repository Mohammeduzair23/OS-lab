#include<stdio.h>
void main()
{
float tot=0,avg,avgtr,totr=0;
int n,i,bt[100],wt[100],tr[100];
printf("Enetr the number of process: \n");
scanf("%d",&n);
printf("Enter the brust time: \n");
for(i=0; i<n; i++) 
{
scanf("%d",&bt[i]);
}
wt[0] = 0;
printf("Waiting time of each process \n");
printf("waiting time of p[%d]=%d",0,wt[0]);
for(i=1;i<n;i++)
{
wt[i]=wt[i-1] + bt[i-1];
printf("waiting time of p[%d]=%d",i,wt[i]);
}

for(i=0; i<n; i++)
{
tot = tot + wt[i];
tr[i] = wt[i] + bt[i];
printf("\n turn around time for p[%d]=%d",i,tr[i]);
totr = totr + tr[i];
}
avg=tot/n;
avgtr=totr/n;

printf("\n average waiting time = %f",avg);
printf("\n average turn around time = %f",avgtr);
}
