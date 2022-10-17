class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.length();
        if(n < 26) return false;
        unordered_set<char> st;
        for(auto i: s) st.insert(i);
        if(st.size() < 26) return false;
        return true;
    }
};