#include <stdio.h>

void print_bytes_as_int(const void *data) {
    // קאסטינג ל־int*
    const int *int_ptr = (const int *)data;
    printf("המספר הוא: %d\n", *int_ptr);
}

int main() {
    int number = 42;
    print_bytes_as_int(&number); // שולח כתובת של int בתור void*
    return 0;
}
