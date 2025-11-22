Aim:
To write a C program to sort a list of integers using the Quick Sort algorithm.

Algorithm:
  
Step 1: Start.
Step 2: Read the number of elements n.
Step 3: Read n elements into the array.
Step 4: Call quickSort(list, 0, n-1).
Step 5: In quickSort() function:
If low < high:
Call partition() to find the pivot position.
Recursively sort the left subarray.
Recursively sort the right subarray.
Step 6: In partition() function:
Choose the last element as the pivot.
Rearrange elements so that:
Elements smaller than pivot are on the left.
Elements greater than pivot are on the right.
Swap pivot to its correct position.
Step 7: Print the sorted array.
Step 8: Stop.

Program:

#include <stdio.h>

//Swap the numbers / Call by referene to persist changes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition 
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}

Input:
Enter number of elements: 7
Enter 7 elements:
64 34 25 12 22 11 90


Output:
Sorted array (Quick Sort): 11 12 22 25 34 64 90

Result:
This program successfully sorts the given array using the Quick Sort algorithm, which is an efficient and fast sorting technique based on the divide-and-conquer method.
