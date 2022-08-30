class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",s2="";
        for(auto i:s){
            if(i == '#' and !s1.empty()) s1.pop_back();
            else if(i == '#' and s1.empty()) continue;
            else s1.push_back(i);
        }
        for(auto i:t){
            if(i == '#' and !s2.empty()) s2.pop_back();
            else if(i == '#' and s2.empty()) continue;
            else s2.push_back(i);
        }
        if(s1.size() != s2.size()) return false;
        return (s1 == s2);
    }
};