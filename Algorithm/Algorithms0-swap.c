

// Swop between to int pointers
void swapPointer(int* x, int* y) {
    auto int tmp = *x;
    *x = *y;
    *y = tmp;
}


void swapPointer_without_tmp(int* x, int* y) {
    /*for the same pointer or the same array place*/
    if (x == y) return; /*if (*x == *y) return*/;
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}



void swapPointer_without_tmp_2(int* x, int* y) {
    /*With xor*/
    if(x == y) return;
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}