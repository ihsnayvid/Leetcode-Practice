class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        vector<int> ans;
        if(s.size() < p.size()) return ans;
        unordered_map<char,int> mp, ms;
        for(auto i: p)
            mp[i]++;
        
        
        int i = 0, j = 0;
        while(j<s.size()){
            ms[s[j]]++;            
            if(j-i+1 == k){
                if(mp == ms)
                    ans.push_back(i);
                ms[s[i]]--;
                if(ms[s[i]] == 0)
                    ms.erase(s[i]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};