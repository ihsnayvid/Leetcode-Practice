class Solution {
public:
    int solve(vector<int> &nums){        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> b(nums.begin() + 1, nums.end());
        return max(solve(a), solve(b));
    }
};