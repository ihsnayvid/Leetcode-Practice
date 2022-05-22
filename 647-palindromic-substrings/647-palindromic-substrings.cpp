class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        int count = 0;
        vector<vector<int>> dp(l, vector<int>(l,0));
        
        for(int i=0; i<l; i++)
            dp[i][i] = 1, count++;
        
        for(int i=1; i<l; i++){
            for(int j=0; j<i; j++){
                if((j+1 ==i and s[i] == s[j]) or (dp[i-1][j+1] == 1 and s[i] == s[j]))
                    dp[i][j] = 1, count++;
            }
        }
        
        return count;
    }
};