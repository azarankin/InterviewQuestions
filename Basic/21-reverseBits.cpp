#include <cstdint>

uint32_t reverseBits(uint32_t r) {
    uint32_t result = 0;

    for (int i = 0; i < sizeof(r)/*32*/; ++i) {
        result <<= 1;         // מזיז את הביטים שמאלה
        uint32_t rightbit = r & 1;
        result |= rightbit;    // מוסיף את הביט הכי ימני של n
        r >>= 1;              // מזיז את n ימינה
        
    }

    return result;
}
