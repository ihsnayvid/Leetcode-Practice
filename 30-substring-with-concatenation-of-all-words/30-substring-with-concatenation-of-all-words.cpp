class Solution {
public:
    
    bool check(unordered_map<string,int> mp, string s, int w){
        for(int j = 0; j < s.size(); j += w){
            string word = s.substr(j,w);
            if(mp.find(word) != mp.end()){
                if(mp[word]-- <= 0)
                    return false;
            }
            else return false;   
        }
        
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        vector<int> ans;
        for(auto i: words)
            mp[i]++;
        
        int w = words[0].length();
        int k = w * words.size();
        
        int i = 0;
        while(i + k <= s.size()){
            string win = s.substr(i,k);
            if(check(mp, win, w))
                ans.push_back(i);
            i++;
        }
        
        return ans;
    }
};