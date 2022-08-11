class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, 0);
        dp[n-1] = true;
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=nums[i] and i+j < n; j++)
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }                    
        }
        
        // for(auto i:dp)
        //     cout<<i<<" ";
        // cout<<endl;   
        return dp[0];
    }
};