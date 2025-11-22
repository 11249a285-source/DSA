Aim:
To write a C program to search for a given element in an array using Recursive Linear Search.

Algorithm:

Step 1: Start.
Step 2: Read the size of the array.
Step 3: Input all elements into the array.
Step 4: Display the dataset.
Step 5: Read the element to be searched.
Step 6: Call the function
LinearSearch(array, size, elementToFind, 0).
Step 7: In the LinearSearch() function:
If index >= size, return -1 (element not found).
If the current element matches the key, return the index.
Otherwise, call the function recursively for the next index.
Step 8: Display whether the element is found or not.
Step 9: Stop.

Program:

#include <stdio.h>
#include <stdbool.h>

int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    if (index >= size)
    {
        return -1;
    }
    if (dataSet[index] == elementToFind)
    {
        return index;
    }
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);

    int searchSpace[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);

    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);
}

Output:
Enter the size of Data Set for Linear Search: 5
Enter the 1 out of 5 element in data set: 10
Enter the 2 out of 5 element in data set: 20
Enter the 3 out of 5 element in data set: 30
Enter the 4 out of 5 element in data set: 40
Enter the 5 out of 5 element in data set: 50

Given Dataset for Linear Search is: 10 - 20 - 30 - 40 - 50 -
Enter the element to find in the dataset: 30
Required element 30 is found in the dataset at position 3 or index 2

Result:
This program successfully performs a linear search using recursion to find a given element in an array. It checks each element one by one until the required element is found or the array ends.
