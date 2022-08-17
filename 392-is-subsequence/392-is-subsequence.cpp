class Solution {
public:
    bool isSubsequence(string t, string s) {
        if(t == "") return true;
        int i = 0, j = 0;
        while(i < s.size()){
            if(s[i] == t[j])
                j++;
            if(j == t.size()) return true;
            i++;
        }
        return false;
    }
};