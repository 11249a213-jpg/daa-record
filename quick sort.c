Algorithm (Without Randomization) 
1. Choose the last element of the current sub-array as the Pivot. 
2. Move all elements smaller than the pivot to its left and all larger elements to its right. 
3. Repeat Step 1 & Step 2 for the left and right sub-arrays independently. 
4. If the sub-array has 1 or 0 elements then it is already sorted; STOP.

 Algorithm (With Randomization) 
1. Pick a random index k between the current low and high boundaries. 
2. Swap the element at index k with the element at the high index. 
3. Choose the last element ("randomly placed") of the current sub-array as the pivot. 
4. Move all elements smaller than the pivot to its left and all larger elements to its right. 
5. Repeat Step 1 & Step 4 for the left and right sub-arrays independently. 
6. If the sub-array has 1 or 0 elements then it is already sorted; STOP.
PROGRAM:
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
 
// Simple swap function to exchange two integers 
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// Standard Partitioning logic 
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j < high; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int randomIndex = low + rand() % (high - low + 1); 
        swap(&arr[randomIndex], &arr[high]); 
 
        int pi = partition(arr, low, high); 
 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
int main() 
{ 
    int n; 
    srand(time(NULL)); 
 
    printf("Enter number of elements: "); 
    if (scanf("%d", &n) != 1 || n <= 0) 
    { 
        printf("Invalid input. Please enter a positive integer.\n"); 
        return 1; 
    } 
 
    int numbersToSort[n]; 
    printf("Enter %d integers: ", n); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &numbersToSort[i]); 
 
    quickSort(numbersToSort, 0, n - 1); 
 
    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", numbersToSort[i]); 

    return 0; 
}
