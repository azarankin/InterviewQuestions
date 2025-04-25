
// can use only add and shift operators


void n_squared_improved(int*arr, int size) //O(n)    3*3 is 4 + (5)
{
    //int arr[100];
    int delta = 1;
    arr[0] = 0;
    for (int i = 1; i < size/*100*/; ++i)
    {
        arr[i] = arr[i - 1] + delta;
        delta += 2;
    }
}


void n_squared(int*arr, int size) //O(n^2)       3*3 is 3+3+3
{
    //int arr[100];
    for (int i = 0; i < size/*100*/; ++i) {
        arr[i] = 0;
        for (int j = 0; j < i; ++j) 
        {
            arr[i] += i;
        }
    }
}


