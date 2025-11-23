Aim:
To write a C program that reverses a string using stack operations (push and pop) implemented with an array.

Algorithm:

1. Start the program.
2. Read the size of the character stack (MAX).
3. Allocate memory for the stack using realloc.
4. Define push(item):
If stack is full, display “Overflow”.
Else increment Top and insert character.
5. Define pop():
If stack is empty, display “Underflow”.
Else return the character at Top and decrement Top.
6. In StringReversal():
Read a string from the user.
Push every character of the string onto the stack.
Pop all characters and print them to get the reversed string.
7. End the program.

Program:

#include <stdio.h>
#include <stdlib.h>

int top = -1;   // Stack top pointer
int size;       // Size of string
char *STACK;    // Dynamic array for stack

// -------------------- PUSH FUNCTION --------------------
void push(char item)
{
    // Check stack overflow
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;      // Increment top
        STACK[top] = item;  // Insert character
    }
}

// -------------------- POP FUNCTION ---------------------
char pop()
{
    char temp = STACK[top]; // Get top element
    top = top - 1;          // Decrease top
    return temp;            // Return popped element
}

int main()
{
    // Ask user for the size of the string
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);

    // Declare input array
    char input[size];

    // Dynamically allocate memory for stack
    STACK = (char *)malloc(size * sizeof(char));

    // Read the string from user
    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", input);

    // Push each character of the string into the stack
    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }

    // Display reversed string
    printf("Reversed string is - \n");

    // Pop each character from the stack and print
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }

    return 0;
}

Output:
Enter the size of string to reverse: 5
Enter the string of size 5 to reverse: HELLO
Reversed string is -
OLLEH


Result:
The program successfully reverses a string using stack operations, demonstrating the LIFO (Last In, First Out) property of stacks.
