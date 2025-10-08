#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"
#include <stdbool.h>

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    int startOfIndex = start; //making the first element in the range the minimum whould be the start of the index
    //looping through the range from start+1 to stop
    for(int i= start +1; i < stop; i++){
        if (array[i] < array[startOfIndex]){
            startOfIndex= i;//update if the smaller value is found
        }
    }
    return startOfIndex; //return the index of the smallest value
}

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
   for (unsigned int i = 0; i < size-1; i++) {
    unsigned int startOfIndex = i;
    //finding the smallest value in the reamiangin sorted part
    for (unsigned int j=i +1; j<size; j++){
        if (array[j]<array[startOfIndex]) {
            startOfIndex=j;
        }
    }
    //swapping the min that was found at position i
    if (startOfIndex != i){
        int temp = array[i];
        array[i] = array[startOfIndex];
        array[startOfIndex] = temp;
    }

    if (print) {
        printf("after passing %u, i+1");
        for (unsigned int k=0;k<size;k++){
            printf("%d", array[k]);
        }
        printf("\n");
    }
}
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    for (unsigned int i = 1; i < size; i++) {
        //curr element to insert into the sorted portion
        int currentElement = array[i];
        int j = i - 1;

        //moving elements that are greater than currentElement one position ahead
        while (j >= 0 && array[j] > currentElement) {
            array[j + 1] = array[j];
            j--;
        }

        //inserting currentElement into the correct position
        array[j + 1] = currentElement;

        //printing the ray after each iteration
        if (print) {
            printf("After pass %u: ", i);
            for (unsigned int k = 0; k < size; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }
    }

}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    
    for (int i = 0; i < size; i ++){
        //loop in order to perform swaps
        //check if there have been any swaps
        bool noSwaps = true;
        for (int j = 0; j < size - i - 1; j++){
        //compare j with j+1, and swap if j is larger value
        //use compare helper function
        int result = compare(&array[j], &array[j + 1]);
        //if result, is more than 0, that means array[j] > array[j + 1]
        if (result > 0){
            swap(&array[j], &array[j + 1]);
            //if there was a swap, set noSwaps to false
            noSwaps = false;
        }
   
    }
    if (print) printIntArray(array, size);
    //if noSwaps is true, then we got through inner loop without any swaps
    //therefore array is already sorted
    if (noSwaps) break;
   
}

}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;

    int i = l;
    int j = m + 1;
    int start = l;

    ///compare arr[I] to arr[j], and copy the lower value into temp
    while (i <= m && j <= r) {
    //if arr[i] is smaller, increment I
    //same for j
        if (arr[i] <= arr[j]){
            temp[start] = arr[i]; 
            i++;
        }else{
            temp[start] = arr[j];
            j++;
        }
        start++;
    }
    //copies remainder of left half
    while (i <= m){
        temp[start] = arr[i]; 
        i++;
        start++;
    }
    //copies remainder of right half 
    while (j <= r) {
        temp[start] =arr[j];
        j++;
        start++;
    }
    //copies sorted values from l to r in temp into arr
    for (int k =l; k <= r; k++){
        arr[k] = temp[k];
    }
   
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (r-l >= 0)
    return;

    int m = (r-l) / 2 +l;
    
    merge_sort(arr, temp, l, m);

    merge_sort(arr, temp, m+1, r);

    merge(arr, temp, l, m, r);

    printIntArray(arr, 10);
   
}

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    printIntArray(array, 10);
    free(temp);
} 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif