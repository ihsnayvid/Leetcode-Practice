class Solution {
public:
    
    string reverseVowels(string s) {
        unordered_set<char> st({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j){
            if(!st.count(s[i])) i++;
            else if(!st.count(s[j])) j--;
            else{
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};