Aim:
To write a C program to implement queue operations using array, including Enqueue, Dequeue, and Display, along with proper handling of overflow and underflow conditions.

Algorithm:

1. Start the program
2. Initialize
front = -1
rear = -1
Read MAX (size of the queue)
Create array queue[MAX]
3. Enqueue Operation
Check if rear == MAX - 1
→ If true, display Queue Overflow
Else:
Read the element item
If queue is empty (front == -1 and rear == -1):
→ set front = rear = 0
Else:
→ rear = rear + 1
Insert item into queue[rear]
4. Dequeue Operation
Check if queue is empty (front == -1 or front > rear)
→ Display Queue Underflow
Else:
Remove element from queue[front]
Increment front = front + 1
If front > rear after deletion:
→ Reset queue → front = rear = -1
5. Display Operation
If queue is empty: print Queue is Empty
Else:
Print all elements from queue[front] to queue[rear]
6. Repeat operations until user chooses Exit
7. Stop the program

Program:

#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;
int *QUEUE; // Dynamic array for queue

// --------------------- ENQUEUE FUNCTION ---------------------
void enqueue(int item)
{
    // Check if queue is full
    if (rear == size - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    // If inserting the first element
    if (front == -1)
        front = 0;

    rear++;                // Move rear pointer
    QUEUE[rear] = item;    // Insert element
    printf("%d inserted into queue.\n", item);
}

// --------------------- DEQUEUE FUNCTION ---------------------
void dequeue()
{
    // Check if queue is empty
    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    // Remove element from the front
    int temp = QUEUE[front];
    front++;
    printf("Deleted element: %d\n", temp);

    // Reset queue when it becomes empty
    if (front > rear)
        front = rear = -1;
}

// --------------------- DISPLAY FUNCTION ---------------------
void display()
{
    // Check if queue is empty
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    // Display elements from front to rear
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

// --------------------- MAIN FUNCTION ---------------------
int main()
{
    int choice, data;

    // Read the size of the queue
    printf("Enter size of Queue: ");
    scanf("%d", &size);

    // Allocate memory dynamically
    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Menu-driven program
    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            free(QUEUE); // Free allocated memory
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

Output:
Enter size of Queue: 3

--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: 10
10 inserted into queue.

--- Queue Menu ---
Enter your choice: 1
Enter data to insert: 20
20 inserted into queue.

--- Queue Menu ---
Enter your choice: 1
Enter data to insert: 30
30 inserted into queue.

--- Queue Menu ---
Enter your choice: 3
Queue elements: 10 20 30

--- Queue Menu ---
Enter your choice: 2
Deleted element: 10

--- Queue Menu ---
Enter your choice: 3
Queue elements: 20 30

--- Queue Menu ---
Enter your choice: 2
Deleted element: 20

--- Queue Menu ---
Enter your choice: 2
Deleted element: 30

--- Queue Menu ---
Enter your choice: 2
Queue Underflow! Nothing to delete.

--- Queue Menu ---
Enter your choice: 4
Exiting...


Result:
The program successfully implements queue operations using an array.
It performs enqueue, dequeue, and display operations correctly and handles overflow and underflow conditions properly.
