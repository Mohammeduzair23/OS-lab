#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, k;
    int pageFaults = 0, found, least;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames and time
    for (i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {
        found = 0;

        // Check if page is in frame
        for (j = 0; j < f; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                time[j] = i + 1;   // update recent use
                break;
            }
        }

        // Page fault
        if (found == 0)
        {
            pageFaults++;

            // Check for empty frame
            for (j = 0; j < f; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pages[i];
                    time[j] = i + 1;
                    found = 1;
                    break;
                }
            }
        }

        // Replace least recently used page
        if (found == 0)
        {
            least = 0;
            for (j = 1; j < f; j++)
            {
                if (time[j] < time[least])
                    least = j;
            }

            frame[least] = pages[i];
            time[least] = i + 1;
        }

        // Display frames
        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
        {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
