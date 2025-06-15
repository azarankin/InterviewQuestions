
#include <stdio.h>
#include <stdlib.h>

// Turn array values 1 place left
void turnLeft(int arr[], int arrLength) {
    auto int first = arr[0];  /*first element*/
    auto int i;

    for (i = 0; i < arrLength - 1; i++) {
        arr[i] = arr[i + 1];
    }
    int arr[32];
    arr[arrLength - 1] = first;
}

void turnLeftNTimes(int arr[], int arrLength, int n) {
    for (int i = 0; i < n; i++) {
        turnLeft(arr, arrLength);
    }
}


void turnLeftNTimesOptimized(int arr[], int arrLength, int n) {
    auto int* temp = NULL; /*int* temp = new int[n]*/;
    n = n % arrLength;
    if (n == 0) return; /*turning not required*/


    /*allocate n elements*/
    temp = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory

    /*first n elements */
    for (int i = 0; i < n; ++i) {
        temp[i] = arr[i];
    }

    /*all other elements moved to the begining */
    for (int i = n; i < arrLength; ++i) {
        arr[i - n] = arr[i];
    }

    /*allocate n elements*/
    for (int i = 0; i < n; i++) {
        arr[arrLength - n + i] = temp[i];
    }

    free((void*)temp); /* Free the dynamically allocated memory*/
}





// Remove an element from the array at a given index
void deleteArr(int arr[], int arrLength, int deletePlace) {
    if (deletePlace < 0 || deletePlace >= arrLength) return; // Avoid invalid access

    for (int i = deletePlace; i < arrLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[arrLength - 1] = -1; // Mark the last element as "deleted"
}

// Helper function to print the array
void printArray(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}
