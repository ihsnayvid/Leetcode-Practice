class Solution {
public:
    unordered_map<string,int> mp;
    bool solve(string s, string word){
        int k = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == word[k]) k++;
            if(k == word.size()) return true;
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for(auto i: words)
            mp[i]++;
        
        for(auto i: mp){
            if(solve(s,i.first))
                ans += i.second;
        }
        return ans;
    }
};