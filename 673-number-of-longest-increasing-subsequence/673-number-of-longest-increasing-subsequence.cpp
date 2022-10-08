class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0, mx = 1, n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    // dp[i] = max(dp[i], 1 + dp[j]);
                    if(1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }
                    else if(1 + dp[j] == dp[i]) count[i] += count[j];
                    mx = max(mx, dp[i]);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dp[i] == mx) ans += count[i];
        }
        return ans;
    }
};