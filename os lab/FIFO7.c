#include<stdio.h>
void print_mem(int mem[], int m)
{
int i;
for(i=0; i<m; i++)
printf("\t%d", mem[i]);
printf("\n");
}
void main()
{
int ref[25], mem[10], i, j, k, flag;
int p, m, n, pf=0;
printf("Enter the no of pages in the references string: ");
scanf("%d", &n);
printf("Enter the frame size: \n");
scanf("%d", &m);
printf("Enter the reference string \n");
for(i=0; i<n; i++)
scanf("%d", &ref[i]);
j=0;
pf=0;
for(i=0; i<m; i++)
mem[i] = -1;
for(i=0; i<n; i++) {
p=ref[i];
flag=0;
for(k=0; k<m; k++) 
if(mem[k]==p)
flag=1;
if(flag!=1) {
mem[j] = p;
j=(j+1)%m;
pf++;
}
printf("%d.....\t", p);
print_mem(mem, m);
}
printf("num of page fault=%d", pf);
}
