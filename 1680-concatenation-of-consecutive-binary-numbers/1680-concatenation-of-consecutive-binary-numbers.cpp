class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, mod = 1e9+7;   
        for(int i=1; i<=n; i++)
            ans = (((ans << (1 + int(log2(i)))) % mod) + i) % mod;        
        
        return ans;
    }
};