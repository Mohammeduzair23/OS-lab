#include <stdio.h>

#define max_size 3
int item[max_size];
int front, rear, size;

//void display();
//void prod();
//void consu();

void display() {
    int k, temp;
    if (size > 0) {
        k = size;
        temp = front;
        printf("Items in buffer are:\n");
        while (k > 0) {
            printf("%d\n", item[temp]);
            temp = (temp + 1) % max_size;
            k--;
        }
    } else {
        printf("Buffer is empty\n");
    }
}

void prod() {
    if (size < max_size) {
        rear = (rear + 1) % max_size;
        printf("Enter the item: ");
        scanf("%d", &item[rear]);
        size++;
    } else {
        printf("Buffer is full\n");
    }
    display();
}

void consu() {
    if (size > 0) {
        printf("Consumed item is: %d\n", item[front]);
        front = (front + 1) % max_size;
        size--;
        display();
    } else {
        printf("Buffer is empty\n");
    }
}

int main() {
    int ch;
    size = 0;
    front = 0;
    rear = -1;

    do {
        printf("\n______PRODUCER CONSUMER PROBLEM_____\n");
        printf("1. Produce item\n2. Consume item\n3. Display buffer\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: prod(); break;
            case 2: consu(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}

