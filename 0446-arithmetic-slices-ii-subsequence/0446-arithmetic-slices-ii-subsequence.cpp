class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;        
        vector<unordered_map<int, int>> dp(n+1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long diff = (long)nums[i] - (long)nums[j];
                if(diff > INT_MAX or diff < INT_MIN) continue;
                dp[i][diff] ++;
                if(dp[j].count(diff)){
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        
        return ans;
    }
};