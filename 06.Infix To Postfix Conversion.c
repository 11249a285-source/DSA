Aim:
To convert a given infix expression to its equivalent postfix expression using a stack.

Algorithm:
  
1.Create an empty stack for operators.
2.Read the infix expression from left to right (character by character).
3.If the character is an operand (letter or digit), append it to the postfix output.
4.If the character is '(', push it onto the stack.
5.If the character is ')', pop from the stack and append to postfix until '(' is popped.
6.If the character is an operator (+ - * / ^), then:
   While the stack is not empty and top of stack has operator of higher or equal precedence (for ^ you may treat as right-associative if needed), pop it and append to postfix.
   Push the current operator onto the stack.
   After the entire infix is processed, pop any remaining operators from the stack and append to postfix.
7.Terminate postfix string and display it.

Program:

#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

void Display()
{
    printf("Current Stack elements are -");
    for (int i = 0; i <= TOP; i++)
    {
        printf("[%c,]", STACK[i]);
    }
    printf("\n");
}

void Push(char item)
{
    if (TOP == MAX - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char Pop()
{
    if (TOP == -1)
    {
        printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        char item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}

char Peek()
{
    if (TOP == -1)
    {
        // printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        return STACK[TOP];
    }
}

int GetPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1; // lowest precedence
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; // highest precedence
    default:
        return 0; // consider it as operand
    }
}

int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &MAX);

    STACK = (char *)malloc(MAX * sizeof(char));
    char infix[MAX];
    char postfix[MAX];

    printf("Please enter the infix string of size %d: ", MAX);
    scanf("%s", infix);

    int TokenPrecedence, j = 0, i = 0;
    char c, temp;

    // Reading one token at a time
    while ((c = infix[i]) != '\0')
    // for (int i = 0; i < MAX; i++)
    {
        // c = infix[i];
        TokenPrecedence = GetPrecedence(c); // Current token at a time
        if (TokenPrecedence > 0)            // Current token is Operator
        {
            while (TokenPrecedence <= GetPrecedence(Peek())) // Current Token <= Stack Top Token
            {
                postfix[j++] = Pop();
            }
            Push(c);
        }
        else // Current token is operand or '(' or ')'
        {
            switch (c)
            {
            case '(':
                Push(c);
                break;
            case ')':
                while (Peek() != '(')
                {
                    postfix[j++] = Pop();
                }
                Pop();
                break;
            default:
                postfix[j++] = c;
                break;
            }
        }
        i++;
    }

    // Pop All remaining tokens from stack
    while (Peek() != '\0')
    {
        char c = Pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';
    printf("Postfix notation is : %s", postfix);
    return 0;
}

Input:
Enter the size of infix expression: 10
Please enter the infix string of size 10: A+B*C


Output:
Postfix notation is : ABC*+


Result:
The given infix expression is successfully converted into its equivalent postfix expression using stack operations.
The program correctly applies the rules of operator precedence and parentheses handling, and displays the postfix form of the entered infix expression.
