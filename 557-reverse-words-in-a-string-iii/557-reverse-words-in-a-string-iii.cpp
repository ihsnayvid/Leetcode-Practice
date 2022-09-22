class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string word;
        stringstream ss(s);
        while(ss >> word){
            reverse(word.begin(), word.end());
            ans += (word + " ");
        }
        ans.pop_back();
        return ans;
    }
};