class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), ans = 1, st = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if((j == i+1 and s[i] == s[j]) or (s[i] == s[j] and dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(j-i+1 > ans){
                        ans = j-i+1;
                        st = i;
                    }
                }
            }
        }
        
        return s.substr(st, ans);
    }
};