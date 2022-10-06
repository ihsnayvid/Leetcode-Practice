class Solution {
public:
    unordered_map<string, int> mp;
    vector<int> dp;
    bool solve(string s, int idx){
        if(idx == s.length()) return true;
        if(mp.count(s)) return true;
        string first = "";
        for(int i=idx; i<s.length(); i++){
            first += s[i];
            if(mp.count(first)){
                int next = (dp[i] != -1 ? dp[i] : (dp[i] =  solve(s, i+1)));
                if(next)
                    return true;
            } 
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto word: wordDict)
            mp[word]++;
        dp.resize(s.length() + 1, -1);
        return solve(s, 0);
    }
};