Aim:
To write a C program to implement stack operations such as push, pop, and display using an array.

Algorithm:

1. Start the program.
2. Read the stack size (MAX).
Initialize Top = -1.
3. Define stack operations:
Push():
If Top == MAX-1, display "Overflow".
Else increase Top and insert item.
Pop():
If Top == -1, display "Underflow".
Else remove and decrease Top.
Display():
Print all elements from index 0 to Top.
4. In main():
Create stack array.
Display menu:
1 → Push
2 → Pop
3 → Exit
Perform the chosen operation using switch–case.
5. Repeat until user selects Exit.
6. End the program.

Program:

#include <stdio.h>
#include <stdlib.h>

int top = -1;   // Top pointer for stack
int size;       // Size of stack
char *STACK;    // Dynamic array for stack

// ---------------------- PUSH FUNCTION ----------------------
void push(char item)
{
    // Check if stack is full
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;     // Move top to next position
        STACK[top] = item; // Insert item
    }
}

// ---------------------- POP FUNCTION -----------------------
void pop()
{
    // If stack is empty
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top]; // Get top element
        top = top - 1;          // Remove element from stack
        printf("Element popped %c", temp);
    }
}

// ---------------------- DISPLAY FUNCTION -------------------
void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }

    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]); // Print all elements from top to bottom
    }
}

// ---------------------- MAIN PROGRAM -----------------------
int main()
{
    int choice;
    char data;

    // Read stack size
    printf("Enter size of stack: ");
    scanf("%d", &size);

    // Dynamic memory allocation for stack
    STACK = (char *)malloc(size * sizeof(char));

    // Infinite loop for menu-driven program
    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf(" %c", &data); // Space before %c to avoid newline issue
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            DisplayStack();
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}


User Input + Program Output:
Enter size of stack: 3

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: A

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: B

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: C

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
[Top]
C
B
A

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Element popped C

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
[Top]
B
A

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting...

Result:
This program successfully demonstrates stack operations using an array, allowing the user to push, pop, and display stack elements.
