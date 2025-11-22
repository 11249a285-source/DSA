Aim:
To write a C program to sort a given array of integers using the Merge Sort technique.

Algorithm:

Step 1: Start.
Step 2: Read the number of elements n.
Step 3: Read n elements into the array.
Step 4: Call mergeSort(arr, 0, n-1).
Step 5: In mergeSort() function:
If left < right:
Find the midpoint using mid = (left + right) / 2.
Recursively sort the left half.
Recursively sort the right half.
Merge the two halves using the merge() function.
Step 6: In merge() function:
Compare elements from both halves.
Store the smaller elements into a temporary array.
Copy remaining elements.
Copy sorted values back to the original array.
Step 7: Print the sorted array.
Step 8: Stop.

Program:

#include <stdio.h>

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    // Merge logic
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy left-out elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy temp back to original
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Left part
        mergeSort(arr, mid + 1, right); // Right part
        merge(arr, left, mid, right);   // Merge halves
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

Input:
Enter number of elements: 6
Enter 6 elements:
38 27 43 3 9 82


Output:
Sorted array (Merge Sort): 3 9 27 38 43 82

Result:
This program successfully sorts the given array using the Merge Sort algorithm, which is a fast and efficient divide-and-conquer sorting method. It is suitable for sorting large data sets.















