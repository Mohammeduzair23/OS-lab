#include <stdio.h>

int main()
{
    int n, i, time = 0, tq;
    int bt[20], rt[20], wt[20], tat[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    // Input burst time
    for (i = 0; i < n; i++)
    {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // remaining time
        wt[i] = 0;
    }

    // Round Robin logic
    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                done = 0;

                if (rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    // Turnaround time calculation
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    

// Calculate total waiting time and turnaround time
for (i = 0; i < n; i++)
{
    avgwt = avgwt + wt[i];
    avgtat = avgtat + tat[i];
}

// Calculate averages
avgwt = avgwt / n;
avgtat = avgtat / n;

// Print averages
printf("\nAverage Waiting Time = %.2f", avgwt);
printf("\nAverage Turnaround Time = %.2f\n", avgtat);

// Output
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (i = 0; i < n; i++)
{
    printf("P%d\t\t%d\t\t%d\t\t%d\n",
           i + 1, bt[i], wt[i], tat[i]);
}

return 0;
} 
