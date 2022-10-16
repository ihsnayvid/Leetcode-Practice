class Solution {
public:
    
    int solve(int idx, int d, int n, vector<int> &jd, vector<vector<int>> &dp){
        if(d == 0 and idx == n) return 0;
        if(d == 0 or idx == n) return INT_MAX;
        if(dp[idx][d] != -1) return dp[idx][d];
        int curr = jd[idx], mn = INT_MAX;
        for(int i=idx; i<n; i++){
            curr = max(curr, jd[i]);
            int nxt = solve(i + 1, d - 1, n, jd, dp);
            if(nxt != INT_MAX)
                mn = min(mn, curr + nxt);
        }
        return dp[idx][d] = mn;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n+1, vector<int> (d+1, -1));
        return solve(0, d, n, jd, dp);        
    }
};