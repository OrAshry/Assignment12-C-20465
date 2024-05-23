/*
* MMN 12 - Q1
* Author: Or Ashry
* Description: This program takes an array of integers as input and computes the partial sums of the array and prints it.
* It consists of two functions:
*   - print_array: This function gets an array(pointer) and the length of the array as parameters,  
*                  and it print the array's values.
*   - partialSums: Function to calculate partial sums of an integer array
*/


#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void print_array(int *a, int s);
int *partialSums(int *array, int size);


/* Function to print an integer array */
void print_array(int *a, int s) {
    int i;

    for(i = 0;i < s;i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

/*
 * Function to calculate partial sums of an integer array
 * 
 * Parameters:
 * - array: Pointer to the integer array 
 * - size: Number of elements in the array
 * 
 * Returns:
 * - Pointer to the array containing partial sums 
 * - Returns 0 if memory allocation fails
 */

int *partialSums(int *array, int size) {
    int i, sum = 0, *sum_array;

    sum_array = (int *)malloc(size * sizeof(int));
    if(!sum_array) {
        printf("memory allocation failed\n");    
	    return 0;
    }

    /* Calculate partial sums */
    for(i = 0;i < size;i++) {
        sum += array[i];
        sum_array[i] = sum;
    }
    return sum_array;
}


int main(void) {
    int array_size, *arr1, *arr2;
    int i;
    
    /* Prompt user to input the number of elements in the array */
    printf("Enter the number of elements: \n");
    scanf("%d", &array_size);
    printf("you chose %d elements\n", array_size);
    
    /* Allocate memory for the original array */
    arr1 = (int *)malloc(array_size * sizeof(int));
    if(!arr1) {
	    printf("memory allocation failed\n");    
	    return 0;
    }
    
    /* Prompt user to input the array values */
    printf("Enter the array values: \n");
    for(i = 0;i < array_size;i++) {
        scanf("%d", &arr1[i]);
    }

    /* Print the input array */
    printf("The array you insert is: ");
    print_array(arr1, array_size);

    /* Calculate partial sums of the array */
    arr2 = partialSums(arr1, array_size);

    /* Print the partial sums array */
    printf("The partial sums array is: ");
    print_array(arr2, array_size);

    /* Free dynamically allocated memory */
    free(arr1);
    free(arr2);
    return 0;
}

