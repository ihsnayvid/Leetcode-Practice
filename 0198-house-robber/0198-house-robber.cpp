class Solution {
public:
//     int solve(int idx, vector<int> &nums, vector<int> &dp){
//         if(idx < 0) return 0;
//         if(idx == 0) return nums[idx];
//         if(dp[idx] != -1) return dp[idx];
        
//         int pick = nums[idx] + solve(idx-2, nums, dp);
//         int nonPick = solve(idx-1, nums, dp);
        
//         return dp[idx] = max(pick, nonPick);
//     }
    int rob(vector<int>& nums){        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};