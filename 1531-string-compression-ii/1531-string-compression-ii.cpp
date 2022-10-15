class Solution {
public:
    int dp[101][101];
    int digits(int c){
        return (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 : 0)));
    }
    int dfs(string &s, int left, int k) {
        int kk = k;
        if(s.size() - left <= k) return 0;
        if(dp[left][k] != -1) return dp[left][k];
        int ans = k ? dfs(s, left + 1, k - 1) : 10000, c = 1;
        for(int i = left + 1; i <= s.size(); ++i) {
            ans = min(ans, dfs(s, i, k) + 1 + digits(c));
            if(i == s.size()) break;
            if(s[i] == s[left]) ++c;
            else if(--k < 0) break;
        }
        return dp[left][kk] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, k);
    }
};