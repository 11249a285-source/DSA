Aim:
To write a C program to create a Binary Search Tree (BST) and perform Level Order Traversal using a queue.

Algortihm:

Step 1: Start the program.
Step 2: Define a Node structure containing:
Data field
Left pointer
Right pointer
Step 3: Create a function createNode() to allocate and initialize a new node.
Step 4: Implement the insert() function to insert elements into the BST:
If root is NULL, create a new node.
If value is less than root data, insert in left subtree.
Else insert in right subtree.
Step 5: Implement Queue functions:
enqueue() to insert nodes into the queue.
dequeue() to remove nodes from the queue.
Step 6: Implement levelOrder() function:
Insert root node into the queue.
While queue is not empty:
Remove a node from the queue.
Print its value.
Insert its left and right children into the queue (if they exist).
Step 7: In main():
Read number of elements.
Allocate memory for the queue.
Read values and insert them into the BST.
Call levelOrder() for traversal.
Step 8: End the program.

Program:

#include <stdio.h>
#include <stdlib.h>

struct Node **queue;
int front = -1, rear = -1, MAX;

// Structure for tree node
// Data, Pointer to left child and Pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Node creation
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert the new node and returns root node of the updated tree
struct Node *insert(struct Node *root, int value)
{
    // First node will be root node
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Queue implementation for Level Order Traversal / BFS


void enqueue(struct Node *temp)
{
    if (rear == MAX-1)
        return; // Queue full
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}

struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Empty
    return queue[front++];
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main()
{
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    printf("Enter %d values:\n", MAX);

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}

Input:
Enter number of elements: 6
Enter 6 values:
50 30 70 20 40 60


Output:
Level Order Traversal: 50 30 70 20 40 60

Result:
This program successfully creates a Binary Search Tree and performs Level Order Traversal using a queue. It helps in understanding how Breadth First Search (BFS) works in tree data structures.




