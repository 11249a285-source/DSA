Aim:
To write a C program to search an element in a sorted array using the Binary Search algorithm.

Algorithm:

1.Start the program.
2.Read the number of elements n from the user.
3.Read the n elements of the array in sorted order.
4.Read the element to be searched (key).
5.Initialize
    low = 0,
    high = n - 1.
6.Repeat while low <= high:
a. Find the middle index: mid = (low + high) / 2.
b. If arr[mid] == key,
    Display that the element is found at position mid + 1.
    Set found = 1 and exit the loop.
c. If arr[mid] < key, set low = mid + 1.
d. Else set high = mid - 1.
7.If the loop ends and found is still 0, display “Element not found”.
8.Stop the program.

Program:

#include <stdio.h>

int main()
{
    int size, targetElement, start, mid, end;

    // Ask the user to enter the size of the array
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Declare the array
    int searchSpace[size];

    // Read elements into the array (array should be sorted for Binary Search)
    for(int i = 0; i < size; i++)
    {
        printf("Enter element %d of %d: ", i, size - 1);
        scanf("%d", &searchSpace[i]);
    }

    // Ask the user to enter the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &targetElement);

    // Initialize start and end positions
    start = 0;
    end = size - 1;

    // Binary Search logic
    while (start <= end)
    {
        // Find the middle index
        mid = (start + end) / 2;

        // If element is found
        if (searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid + 1);
            return 0;
        }
        // If middle element is less than target, search right half
        else if (searchSpace[mid] < targetElement)
        {
            start = mid + 1;
        }
        // If middle element is greater than target, search left half
        else
        {
            end = mid - 1;
        }
    }

    // If element is not found
    printf("Element doesn't exist in the given search set");

    return 0;
}

Input:
Enter the size of array: 5
Enter element 0 of 4: 10
Enter element 1 of 4: 20
Enter element 2 of 4: 30
Enter element 3 of 4: 40
Enter element 4 of 4: 50
Enter the element to search: 30


Output:
Element found at index of 2 (i.e. at position 3)

Result:
This program uses binary search to quickly find an element in a sorted array and displays whether the element is found or not.
