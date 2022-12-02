class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if( n != m) return false;
        unordered_map<char, int> mp1, mp2;
        multiset<int> st1, st2;
        unordered_set<char> ch1, ch2;
        for(auto i: word1) mp1[i]++, ch1.insert(i);
        for(auto i: mp1) st1.insert(i.second);
        
        for(auto i: word2) mp2[i]++, ch2.insert(i);
        for(auto i: mp2) st2.insert(i.second);
        
        return st1 == st2 and ch1 == ch2;
    }
};