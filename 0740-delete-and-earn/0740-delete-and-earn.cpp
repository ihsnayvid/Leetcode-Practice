class Solution {
public:
    
    int solve(vector<int> &dp, vector<int> &sum, int idx, int n){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int a = sum[idx] + solve(dp, sum, idx + 2, n);  //picking ith elt -> cant pick i+1 th
        int b = solve(dp, sum, idx + 1, n);
        
        return dp[idx] = max(a, b);
    }
    int deleteAndEarn(vector<int>& nums) {
        int mx = 2e4 + 1;
        vector<int> sum(mx, 0);
        vector<int> dp(mx, -1);
        
        for(int i: nums) sum[i] += i;   //total sum that can be earned if we pick this num
        
        return solve(dp, sum, 0, mx);        
    }
};