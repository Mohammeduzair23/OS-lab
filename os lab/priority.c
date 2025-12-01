#include<stdio.h>
void main()
{
int x, n, p[10],pt[10], bt[10], wt[10], tr[10], i, j, tot=0, totr=0;
float awt, atr;
printf("Enter the number of process:\n");
scanf("%d", &n);
printf("Enter process: burst time and priority\n");
for(i=0; i<n;i++)
{
printf("\nprocess number %d: ",i);
scanf("%d %d", &bt[i], &pt[i]);
p[i]=i+1;
}
for(i=0; i<n-1; i++)
{
for(j=i+1; j<n; j++)
{
if(pt[i] > pt[j])
{
x=pt[i];
pt[i]=pt[j];
pt[j]=x;
x=bt[i];
bt[i]=bt[j];
bt[j]=x;
x=p[i];
p[i]=p[j];
p[j]=x;
}
}
}
wt[0]=0;
printf("Enter the waiting time of each process:");
printf("\n waiting time of p[%d]=%d\n",0,wt[0]);
for(i=1; i<n; i++)
{
wt[i]=wt[i-1]+bt[i-1];
printf("\n wating time p[%d]=%d",i,wt[i]);
}
for(i=0; i<n; i++)
{
tot=tot + wt[i];
tr[i] = wt[i] + bt[i];
printf("\n turn around time for p[%d]=%d",i,tr[i]);
totr=totr+tr[i];
}
awt=tot/n;
atr=totr/n;
printf("average time=%f", awt);
printf("average turn around time=%f",atr);
}
