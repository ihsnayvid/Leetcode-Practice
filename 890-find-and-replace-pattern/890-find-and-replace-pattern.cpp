class Solution {
public:
    vector<char> solve(string s){
        vector<char> v;
        char idx = 'a';
        unordered_map<char,char> mp;
        
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = idx++;
            v.push_back(mp[s[i]]);
        }
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        vector<char> pt = solve(pattern);
        for(auto i: words){
            if(pt == solve(i))
                ans.push_back(i);
        }
        
        return ans;
    }
};