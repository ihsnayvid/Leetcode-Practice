class Solution {
public:
    bool isAnagram(string s, string t) {        
        if(s.length() != t.length()) return false;
        unordered_map<char,int> ms,mt;
        for(auto i:s) ms[i]++;
        for(auto i:t) mt[i]++; 
        
        return ms == mt;
    }
};