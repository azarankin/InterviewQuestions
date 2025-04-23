uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; ++i) {
        result <<= 1;         // מזיז את הביטים שמאלה
        result |= (n & 1);    // מוסיף את הביט הכי ימני של n
        n >>= 1;              // מזיז את n ימינה
    }

    return result;
}
