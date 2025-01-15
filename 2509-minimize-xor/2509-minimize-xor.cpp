class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int num2_bits = __builtin_popcount(num2);  // Count the number of set bits in num2
    int result = 0;
    
    // Step 1: Try to match set bits of num2 with num1 to minimize XOR
    for (int i = 31; i >= 0; --i) {
        if ((num1 >> i) & 1 && num2_bits > 0) {
            // If num1 has a set bit at this position and we still have set bits to place
            result |= (1 << i);
            num2_bits--;
        }
    }
    
    // Step 2: Place remaining set bits in the smallest possible positions
    for (int i = 0; i < 32 && num2_bits > 0; ++i) {
        if (!((num1 >> i) & 1)) {
            // If num1 has a 0 bit at this position, place remaining set bits
            result |= (1 << i);
            num2_bits--;
        }
    }
    
    return result;
        
    }
};