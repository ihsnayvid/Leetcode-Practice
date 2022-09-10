class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = n;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i=0; i<n; i++) dp[i][i] = true;
        
        for(int g=1; g<n; g++){
            for(int i = 0, j = g; j<n; i++, j++){
                if((g == 1 and s[i] == s[j]) or (s[i] == s[j] and dp[i+1][j-1])){
                    dp[i][j] = true;
                    count++;
                }
            }
        }        
        
        return count;
    }
};