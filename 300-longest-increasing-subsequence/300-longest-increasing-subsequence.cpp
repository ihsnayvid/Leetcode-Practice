class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int prev, vector<int> &nums){
        if(idx == nums.size()) return 0;
        if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
        int ans = solve(idx+1, prev, nums);   //not pick
        if(prev == -1 or nums[idx] > nums[prev])    //pick
            ans = max(ans, 1 + solve(idx+1, idx, nums));
        return dp[idx][prev + 1] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), vector<int> (nums.size() + 1, -1));
        return solve(0, -1, nums);
    }
};