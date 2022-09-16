class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(vector<int> &nums, vector<int> &mul, int st, int en, int i){
        if(i == mul.size()) return 0;
        
        if(dp[st][i] != -1e9) return dp[st][i];
        
        long long start = (nums[st] * mul[i]) + solve(nums, mul, st+1, en, i+1);
        long long end = (nums[en] * mul[i]) + solve(nums, mul, st, en-1, i+1);
        
        dp[st][i] = max(start, end);
        return dp[st][i];
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        dp.resize(1001, vector<int>(1001,-1e9));
        return solve(nums, mul, 0, nums.size()-1, 0);        
    }
};