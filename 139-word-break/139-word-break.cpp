class Solution {
public:
    // vector<int> dp;
    // bool solve(string s, int idx){
    //     if(idx == s.length()) return true;
    //     if(mp.count(s)) return true;
    //     string first = "";
    //     for(int i=idx; i<s.length(); i++){
    //         first += s[i];
    //         if(mp.count(first)){
    //             int next = (dp[i] != -1 ? dp[i] : (dp[i] =  solve(s, i+1)));
    //             if(next)
    //                 return true;
    //         } 
    //     }
    //     return false;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        
        for(auto word: wordDict)
            mp[word]++;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for(int i=1; i<=s.length(); i++){
            string first = "";
            for(int j=i-1; j>=0; j--){
                dp[i] = mp.count(first = s[j] + first) and dp[j];
                if(dp[i]) break;
            }
        }
        return dp[s.length()];
    }
};