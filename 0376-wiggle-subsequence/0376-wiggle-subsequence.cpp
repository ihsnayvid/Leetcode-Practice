class Solution {
public:
    int solve(int idx, int n, vector<int> &nums, int sign, vector<vector<int>> &dp){
        if(idx >= n) return 0;
        if(dp[idx][sign] != -1) return dp[idx][sign];
        
        int pick = 0, notpick = 0;
        if((nums[idx] > 0 and sign) or (nums[idx] < 0 and !sign))
            pick = 1 + solve(idx+1, n, nums, !sign, dp);
        
        notpick = solve(idx+1, n, nums, sign, dp);
        return dp[idx][sign] = max(pick, notpick);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff;
        for(int i=1; i<n; i++){
            int d = nums[i] - nums[i-1];
            if(d) diff.push_back(d);
        }
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return max(solve(0, diff.size(), diff, 1, dp), solve(0, diff.size(), diff, 0, dp)) + 1;
    }
};