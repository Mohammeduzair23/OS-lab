#include <stdio.h>

int main()
{
    int n, temp, i, j;
    int p[10], pt[10], bt[10], wt[10], tat[10];
    float tot = 0, tottat = 0, awt, atat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pt[i]);
        p[i] = i + 1;
    }

    // Sorting based on priority (lower value = higher priority)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(pt[i] > pt[j]) {
                temp = pt[i]; pt[i] = pt[j]; pt[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i]  = p[j];  p[j]  = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        tot += wt[i];
        tottat += tat[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i], bt[i], pt[i], wt[i], tat[i]);
    }

    awt = tot / n;
    atat = tottat / n;

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);

    return 0;
}
