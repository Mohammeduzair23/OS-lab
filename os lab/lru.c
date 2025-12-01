/*#include<stdio.h>
void print_mem(int mem[], int m)
{
int i;
for(i=0; i,m; i++)
printf("\t %d", mem[i]);
printf("\n");
}
int optimal1(int p, int ref[], int c)
{
int i;
for(i=c-1; i>0; i--)
{
if(ref[i] == p)
return i;
}
return -99;
}
int optimal2(int index[], int m)
{
int i, min=20;
for(i=0; i<m; i++)
if(min > index[i])
min = index[i];
return min;
}
void main()
{
int ref[25], mem[10], index[10], i, j, k, flag;
int m, n, p, pf=0;
printf("Enter the number of pages in the references string \n");
scanf("%d", &n);
printf("Enter the frame size: \n");
scanf("%d", &m);
printf("Entern the references string; \n");
for(i=0; i<n; i++)
scanf("%d", &ref[i]);
j=0;
for(i=0; i<m; i++)
mem[i]=-1;
for(i=0; i<n; i++)
{
p = ref[i];
flag = 0;
for(k=0; k<m; k++)
if(mem[k] == p)
{
flag = 1;
break;
}
else
if(mem[k] == -1)
{
mem[k] = p;
pf++;
flag = 1;
break;
}
if(flag ==0 )
{
pf++;
for(k=0; k<m; k++)
index[k] = optimal1(mem[k], ref, i);
for(k=0; k<m; k++)
if(index[k] == -99)
{
mem[k] = n;
flag=1;
break;
}
if(flag==0)
{
j=optimal2(index, m);
for(k=0; k<m; k++)
if(mem[k] == ref[j])
mem[k] = p;
}
}
printf("%d", p);
print_mem(mem, m);
}
printf("Number of page fault= %d", pf);
}

*/


#include<stdio.h>

void print_mem(int mem[], int m)
{
    int i;
    for(i=0; i<m; i++)
        printf("\t %d", mem[i]);
    printf("\n");
}

// Returns the last-used time of page p
int lru_index(int p, int ref[], int current)
{
    int i;
    for(i = current - 1; i >= 0; i--)
        if(ref[i] == p)
            return i;   // last used position
    return -1;          // page never used before
}

// Find the page with the smallest last-used index
int find_lru(int index[], int m)
{
    int i, min = 999, pos = 0;
    for(i = 0; i < m; i++)
    {
        if(index[i] < min)
        {
            min = index[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int ref[25], mem[10], index[10];
    int i, j, k, flag;
    int m, n, p, pf=0;

    printf("Enter the number of pages in the reference string:\n");
    scanf("%d", &n);

    printf("Enter the frame size:\n");
    scanf("%d", &m);

    printf("Enter the reference string:\n");
    for(i=0; i<n; i++)
        scanf("%d", &ref[i]);

    for(i=0; i<m; i++)
        mem[i] = -1;

    for(i=0; i<n; i++)
    {
        p = ref[i];
        flag = 0;

        // Check if page is already present
        for(k=0; k<m; k++)
        {
            if(mem[k] == p)
            {
                flag = 1;  // HIT
                break;
            }
        }

        // MISS
        if(flag == 0)
        {
            pf++;

            // If empty frame exists
            for(k=0; k<m; k++)
            {
                if(mem[k] == -1)
                {
                    mem[k] = p;
                    flag = 1;
                    break;
                }
            }

            // No empty frame → LRU replacement
            if(flag == 0)
            {
                for(k=0; k<m; k++)
                    index[k] = lru_index(mem[k], ref, i);

                j = find_lru(index, m);
                mem[j] = p;
            }
        }

        printf("%d", p);
        print_mem(mem, m);
    }

    printf("Number of page faults = %d\n", pf);
    return 0;
}

