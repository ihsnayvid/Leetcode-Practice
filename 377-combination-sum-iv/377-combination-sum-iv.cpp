class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.resize(1001);
        fill(dp.begin(), dp.end(), -1);
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        if(target < 0)  return 0;
        if(target == 0) return 1;
        if(dp[target] != -1)    return dp[target];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += combinationSum4(nums, target-nums[i]);
        }
        return dp[target] = ans;
    }
};   