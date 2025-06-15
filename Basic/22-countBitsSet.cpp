
#include <cstdint>

int countBitsSet(uint32_t r) {
    int count = 0;
    while (r) {
        uint32_t rightbit = r & 1;
        r >>= 1;

        //if(0b1 == rightbit) ++count;
        count += rightbit;
        
    }
    return count;
}
