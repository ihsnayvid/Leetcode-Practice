class Solution {
public:
    
    long ncr(int n, int r){
        long p = 1, k = 1;
 
        if (n - r < r) r = n - r;
        if(r == 0) return 1;       
        while (r) {
            p *= n;
            k *= r;
            long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
        return p;        
    }
    
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
    
        vector<int> dp(rowIndex+1, 0);
        dp[0] = 1, dp[rowIndex] = 1;
        
        int i = 1, j = rowIndex-1, n = 1;
        while(i<=j){
            dp[i] = ncr(rowIndex, n);
            dp[j] =  ncr(rowIndex, n);
            i++, j--, n++;
        }
        return dp;
    }
};