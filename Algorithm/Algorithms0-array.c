//	Array swop, begin to end [1, 2, 3] to [3, 2, 1]
void arrSwap(int arr[], int arrLength) {
    auto int i;
    auto int tmp;

    for (i = 0; i <= ((arrLength - 1) / 2); i++) {
        tmp = arr[i];
        arr[i] = arr[arrLength - i - 1];
        arr[arrLength - i - 1] = tmp;
    }
}

//	The biggest value in the array
// Condition, at least 2 elements inside the array!
int biggest(int arr[], int arrLength) {
    auto int b = arr[0];   /*biggest*/
    auto int i;
    for (i = 1;i < arrLength;i++)
        if (b < arr[i]) b = arr[i];
    return b;
}

//	The biggest 3rd element
#include <limits.h> // For INT_MIN
int biggest3(int arr[], int arrLength) {
    auto int b1 = INT_MIN;
    auto int b2 = INT_MIN;
    auto int b3 = INT_MIN;
    auto int i;

    for (i = 0; i < arrLength; i++) {
        //if(arr[i]<b3) continue;
        if (arr[i] >= b1) { b3 = b2; b2 = b1; b1 = arr[i]; }
        else if (/*arr[i]<=b1 &&*/ arr[i] > b2) { b3 = b2; b2 = arr[i]; }
        else if (/*arr[i]<=b2 &&*/ arr[i] > b3) b3 = arr[i];
    }
    return b3;
}


//	Compare 2 strings
int charCompare(char* str1, char* str2) {
    auto int i;
    for (i = 0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i]) return 0;
    }
    if (str1[i] || str2[i]) return 0;
    return 1;
}


// String character counter
int stringLength(char str[]) {
    auto int count = 0;
    auto int i;
    for (i = 0; str[i]; i++) count++;
    return count;
}

// Swop chars
void swapChar(char* x, char* y) {
    auto char tmp = *x;
    *x = *y;
    *y = *x;
}


// Swop the string
void stringSwop(char str[]) {
    auto int i;
    auto char tmp;
    auto int length = stringLength(str);
    for (i = 0; i <= ((length - 1) / 2); i++) {
        swapChar(&str[i], &str[length - i - 1]);
        /*tmp = str[i];*/
        /*str[i] = str[length - i - 1];*/
        /*str[length - i - 1] = tmp;*/
    }
}


// //	Merge 2 arrays
// void mergeArray(int merge[], int arr1[], int length1, int arr2[], int length2) {
//     for (int i = 0; i < length1; i++)
//         merge[i] = arr1[i];
//     for (int i = 0; i < length2; i++)
//         merge[length1 + i] = arr2[i]; /*continue merge array after [length1-1]*/
// }


//	Merge 2 arrays with sorting
    // The 2 arrays are sorted
void mergeArraySort(int merge[], int arr1[], int length1, int arr2[], int length2) {
    auto int i, j, m; /*array1, array2, merged array counters*/
    i = j = m = 0;
    while (i < length1 && j < length2) {
        if (arr1[i] <= arr2[j]) {
            merge[m++] = arr1[i++];
        }
        else {
            merge[m++] = arr2[j++];
        }
    }

    /* one of the arrays is empty*/

    /* Copy remaining elements from arr1 (if any)*/
    while (i < length1) {
        merge[m++] = arr1[i++];
    }

    /* Copy remaining elements from arr2 (if any)*/
    while (j < length2) {
        merge[m++] = arr2[j++];
    }
}



//	Sort arrays
void bubleSortArray(int arr[], int arrLength) {
    auto int i;
    auto int tmp;
    for (i = 0; i < arrLength; ++i)
        for (int j = i + 1; j < arrLength; ++j)
            if (arr[i] > arr[j]) {/*swop values inside array for buble sort*/
                /*swap(&arr[i], &arr[j]);*/
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
}

