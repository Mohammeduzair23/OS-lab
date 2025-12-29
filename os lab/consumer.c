#include <stdio.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int count = 0;

void produce()
{
    int item;
    if (count == SIZE)
    {
        printf("Buffer is FULL. Cannot produce.\n");
        return;
    }

    printf("Enter item to produce: ");
    scanf("%d", &item);

    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;

    printf("Produced item: %d\n", item);
}

void consume()
{
    int item;
    if (count == 0)
    {
        printf("Buffer is EMPTY. Cannot consume.\n");
        return;
    }

    item = buffer[out];
    out = (out + 1) % SIZE;
    count--;

    printf("Consumed item: %d\n", item);
}

void display()
{
    int i;
    if (count == 0)
    {
        printf("Buffer is EMPTY.\n");
        return;
    }

    printf("Buffer contents: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", buffer[(out + i) % SIZE]);
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    { // This printf statement can be written in single to 
        printf("\n--- Producer Consumer Menu ---\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Display Buffer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            produce();
            break;
        case 2:
            consume();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
