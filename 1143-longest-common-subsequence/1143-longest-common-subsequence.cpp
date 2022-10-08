class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string &s1, string &s2, int idx1, int idx2){
        if(idx1 == s1.size() or idx2 == s2.size()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int ans;
        if(s1[idx1] == s2[idx2])
            ans = 1 + lcs(s1, s2, idx1+1, idx2+1);
        else
            ans =  max(lcs(s1, s2, idx1, idx2+1), lcs(s1, s2, idx1+1, idx2));
        return dp[idx1][idx2] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1, vector<int> (text2.size() + 1, -1));
        return lcs(text1, text2, 0, 0);   
    }
};