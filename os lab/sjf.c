#include<stdio.h>
void main()
{
float tot=0, avg, avgtr, totr=0;
int i,j, n, x, bt[100], wt[100], tr[100];
printf("Enetr the number of process:");
scanf("%d", &n);
printf("Enetr the brust time:\n");
for(i=0; i<n; i++) 
{
scanf("%d", &bt[i]);
}
for(i=0; i<n; i++)
{
for(j=i+1; j<n; j++)
{
if(bt[i] > bt[j])
{
x = bt[i];
bt[i] = bt[j];
bt[j] = x; 
}
}
}
wt[0] = 0;
printf("waiting time of each process:\n");
printf("\n waiting time of p[%d]=%d\n",0, wt[i]);
for(i=1; i<n; i++)
{
wt[i] = wt[i-1] + bt[i-1];
printf("waiting time of p[%d]=%d",i, wt[i]); 
}
for(i=0; i<n; i++) 
{
tot = tot + wt[i];
tr[i] = wt[i] + bt[i];
printf("\n turn around time for p[%d]=%d",i,tr[i]);
totr = totr + tr[i];
}
avg = tot/n;
avgtr = totr/n;
printf("\n Average waiting time = %f",avg);
printf("\n Average turn around time = %f", avgtr);
}
