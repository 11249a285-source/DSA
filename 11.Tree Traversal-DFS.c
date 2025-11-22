Aim: 
To write a C program that creates a Binary Search Tree (BST) and performs Preorder, Inorder, and Postorder traversals.

Algortihm:

Step 1: Start the program.
Step 2: Define a structure Node with:
data
Pointer to left child
Pointer to right child
Step 3: Create a function createNode() to allocate memory for a new node.
Step 4: Define an insert() function:
If root is NULL, create a new node.
If value is less than root, insert in left subtree.
Otherwise, insert in right subtree.
Step 5: Define traversal functions:
preorder() → Root → Left → Right
inorder() → Left → Root → Right
postorder() → Left → Right → Root
Step 6:
Read number of elements.
Insert each element into the BST.
Step 7:
Display the results of all three traversals.
Step 8: Stop the program.

Program:

#include <stdio.h>
#include <stdlib.h>

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

// Preorder - Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder - Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder - Left -> Right -> Root
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{

    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}

Input:
Enter number of elements: 5
Enter 5 values:
50 30 70 20 40


Output:
Preorder Traversal: 50 30 20 40 70
Inorder Traversal: 20 30 40 50 70
Postorder Traversal: 20 40 30 70 50

Result:
This program successfully creates a Binary Search Tree and performs Preorder, Inorder, and Postorder traversals. It helps in understanding how BST stores data and how different tree traversal methods work.
