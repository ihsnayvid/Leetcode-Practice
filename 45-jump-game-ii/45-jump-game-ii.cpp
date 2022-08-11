class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-2; i>=0; i--){
            int minCost = 10000;
            for(int j=1; j<=nums[i] and i+j <= n; j++){
                minCost = min(minCost, dp[i+j]);
            }
            dp[i] = minCost + 1;
        }
        // for(auto i: dp)
        //     cout<<i<<" ";
        // cout<<endl;
        return dp[0];
    }
};