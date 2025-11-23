Aim:
To write a C program that performs linear search on an array to find the position of a given element.

Algorithm:

1.Start the program.
2.Read the size of the array (n).
3.Read n elements into the array.
4.Read the element to be searched (key).
5.Traverse the array from index 0 to n–1.
6.If any element matches key, print its position and stop the search.
7.If the loop ends without a match, print “Element not found”.
8.End the program.

Program:

#include <stdio.h>
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d",&size);

    int searchSpace[size];
    for(i=0; i<=size-1; i++)
    {
        printf("Enter the %d out of %d element in data set: ",i+1, size);
        scanf("%d",&searchSpace[i]);
    }

    //printf("Given Dataset for Linear Search is: ");
    for(int i=0; i<size; i++)
    {
        printf("%d - ",searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d",&elementToFind);
    i =0;
    while(i<size)
    {
        if(searchSpace[i] == elementToFind)
        {
            printf("Required element %d is found in the dataset at position %d or index %d",elementToFind, i+1, i);
            return 0;
        }
        i++;
    }

    printf("Required element %d is NOT found in the dataset!!!",elementToFind);
}

Input given by user:
Enter the size of Data Set for Linear Search: 5
Enter the 1 out of 5 element in data set: 10
Enter the 2 out of 5 element in data set: 20
Enter the 3 out of 5 element in data set: 30
Enter the 4 out of 5 element in data set: 40
Enter the 5 out of 5 element in data set: 50
10 - 20 - 30 - 40 - 50 - 
Enter the element to find in the dataset: 30


Output:
Required element 30 is found in the dataset at position 3 or index 2

Result:
This program searches an element in an array using linear search and correctly displays whether the element is found or not.

