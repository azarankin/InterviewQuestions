#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void fill_array_with_random(int *arr, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = get_random_number(min, max);
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // לאתחול הרנדום

    int array[10];
    fill_array_with_random(array, 10, 1, 100);
    print_array(array, 10);

    return 0;
}
