class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> ans;
        if(n == 0) return {0};
        else if(n == 1) return {0,1};
        vector<int> dp(n+1,0);
        dp[0] = 0;
        ans.push_back(dp[0]);
        dp[1] = 1;
        ans.push_back(dp[1]);
        
        for(int i=2; i<=n; i++){
            int last = i & 1;
            dp[i] = dp[i>>1] + last;
            ans.push_back(dp[i]);
        }
        return ans;
    }
};