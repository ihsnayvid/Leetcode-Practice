class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 10000);
        dp[n-1] = 0;
        dp[n] = 0;
        for(int i=n-2; i>=0; i--){
            for(int j=1; j<=nums[i] and i+j < n; j++){
                dp[i] = min(dp[i], 1 + dp[i+j]);
            }
        }
        // for(auto i: dp)
        //     cout<<i<<" ";
        // cout<<endl;
        return dp[0];
    }
};