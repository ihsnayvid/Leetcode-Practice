class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) return "";
        
        set<char> st(s.begin(), s.end());
        for(int i=0; i<s.size(); i++){
            if(!st.count(tolower(s[i])) or !st.count(toupper(s[i]))){
                string first = longestNiceSubstring(s.substr(0,i));
                string second = longestNiceSubstring(s.substr(i+1));
                if(first.size() >= second.size()) return first;
                return second;
            }
        }
        return s;
    }
};