class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for (int j = 0; j < 32; j++){
              if (n & (1 << j))
                  count++;
        }
        return count;
    }
};