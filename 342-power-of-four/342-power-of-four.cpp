class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        int total = floor(log2(n) + 1);
        int one = __builtin_popcount(n);
        int zero = total - one;
        return (one == 1 and !(zero & 1));        
    }
};