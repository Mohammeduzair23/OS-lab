/*#include<stdio.h>   
int main() 
{
int i, j, k, l, m, n, p, c=0, s;
int a[20], b[20], q, max;
printf("Enter the number of references string: ");
scanf("%d", &n);
printf("Enter the size of the frame: ");
scanf("%d", &m);
printf("Enter the elements of the references string: \n");
for(i=0; i<n; i++)
scanf("%d", &a[i]);
for(j=0; j<m; j++)
b[j] = -1;
for(i=0; i<n; i++){
for(k=0; k<m; k++)
if(b[k] == a[i])
for(i=0; i<m; i++){                                     $$$  DOWN IS CORRECT CODE   $$$
if(b[j] == -1) {
b[j] = a[i];
c++;
}
}
if(j == m) {
l=i+1, max=0;
for(j=0; j<m; j++) {
for(s=1; s<n; s++) {
if(a[s] == b[j]) {
if(s > max)
{
max = s;
p = j;
}
break;
}
if(s == n) {
max=s;
p=j;
}
}
}
b[p] = a[i];
c++;
printf("\n\n");
for(k=0; k<m; k++)
printf("\n number of page fault is: %d", c);
return 0;
}
}
}
*/

/*
#include <stdio.h>

int main() {
    int n, m;
    int a[20], b[20];
    int i, j, k, s;
    int faults = 0;

    printf("Enter the number of reference strings: ");
    scanf("%d", &n);

    printf("Enter the size of the frame: ");
    scanf("%d", &m);

    printf("Enter the reference string elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize frames
    for (j = 0; j < m; j++)
        b[j] = -1;

    // Process each reference
    for (i = 0; i < n; i++) {
        int hit = 0;

        // Check if page already in frame
        for (j = 0; j < m; j++) {
            if (b[j] == a[i]) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            int replace = -1, farthest = -1;

            // Look for an empty frame
            for (j = 0; j < m; j++) {
                if (b[j] == -1) {
                    replace = j;
                    break;
                }
            }

            // If no empty frame → apply optimal replacement
            if (replace == -1) {
                for (j = 0; j < m; j++) {
                    int nextUse = -1;

                    for (s = i + 1; s < n; s++) {
                        if (a[s] == b[j]) {
                            nextUse = s;
                            break;
                        }
                    }

                    if (nextUse == -1) {   // Not used again → best to replace
                        replace = j;
                        break;
                    }

                    if (nextUse > farthest) {
                        farthest = nextUse;
                        replace = j;
                    }
                }
            }

            b[replace] = a[i];
            faults++;
        }

        // Print frames
        printf("After reference %d: ", a[i]);
        for (k = 0; k < m; k++)
            printf("%d ", b[k]);
        printf("\n");
    }

    printf("\nTotal page faults = %d\n", faults);

    return 0;
}
*/


#include<stdio.h>

int main() 
{
    int i, j, k, l, m, n, p, c = 0, s;
    int a[20], b[20], q, max;

    printf("Enter the number of references string: ");
    scanf("%d", &n);

    printf("Enter the size of the frame: ");
    scanf("%d", &m);

    printf("Enter the elements of the references string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (j = 0; j < m; j++)
        b[j] = -1;

    for (i = 0; i < n; i++)
    {
        int found = 0;

        // check hit
        for (k = 0; k < m; k++)
        {
            if (b[k] == a[i])
            {
                found = 1;
                break;
            }
        }

        // if miss
        if (!found)
        {
            // check empty frame
            for (j = 0; j < m; j++)
            {
                if (b[j] == -1)
                {
                    b[j] = a[i];
                    c++;
                    found = 1;
                    break;
                }
            }

            // no empty → optimal replace
            if (!found)
            {
                max = -1;
                p = -1;

                for (j = 0; j < m; j++)
                {
                    for (s = i + 1; s < n; s++)
                    {
                        if (a[s] == b[j])
                        {
                            if (s > max)
                            {
                                max = s;
                                p = j;
                            }
                            break;
                        }
                    }

                    if (s == n)   // not used again
                    {
                        p = j;
                        break;
                    }
                }

                b[p] = a[i];
                c++;
            }
        }

        printf("\nFrame contents: ");
        for (k = 0; k < m; k++)
            printf("%d ", b[k]);
    }

    printf("\n\nNumber of page faults is: %d\n", c);

    return 0;
}

