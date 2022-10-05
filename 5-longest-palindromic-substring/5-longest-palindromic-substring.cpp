class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), len = 1, st = 0;
        vector<vector<bool>> dp(n, vector<bool> (n));
        
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] and (j == i+1 or dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(j-i+1 > len){
                        len = j-i+1;
                        st = i;
                    }
                }
            }
        }
        
        return s.substr(st, len);
    }
};