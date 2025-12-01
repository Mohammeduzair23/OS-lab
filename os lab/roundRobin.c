#include<stdio.h>
//#include<conio.h>
void main() 
{
int i, NOP, sum=0, count=0, y, quant, wt=0, tat=0,bt[10], temp[10];
float avg_wt, avg_tat;
printf("Total number of process in system: ");
scanf("%d", &NOP);
y=NOP;
for(i=0; i<NOP; i++)
{
printf("\nEnter the brust time of the process[%d]\n", i+1);
scanf("%d", &bt[i]);
temp[i] = bt[i]; 
}
printf("Enetr the time quantum for the process: \t");
scanf("%d", &quant);
printf("\n process NO \t\t burst time \t\t TAT \t\t Waiting time");
for(sum=0; i=0; y!=0)
{
if(temp[i] <= quant && temp[i]>0)
{
sum=sum+temp[i];
temp[i]=0;
count=1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - quant;
sum = sum + quant;
}
if(temp[i] ==0 && count==1)
{
y--;
printf("\n process NO[%d]\t\t %d \t\t\t\t %d \t\t\t %d", i+1, bt[i], sum,bt[i]);
wt=wt+sum-bt[i];
tat=tat+sum;
count=0;
}
if(i==NOP-1)
{
i=0;
}
else{
i++;
}
}
avg_wt = wt*1.0/NOP;
avg_tat = tat*1.0/NOP;
printf("\n Average waiting time : \t %f", avg_wt);
printf("\n Average turn around time : \t %f", avg_tat);
//getch();  
}
