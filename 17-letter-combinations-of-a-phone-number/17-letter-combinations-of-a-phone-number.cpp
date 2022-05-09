class Solution {
public:
    vector<string> ans;
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
    void solve(string digits, string tmp, int i, int n){
        if(i > n) return;
        else if(i == n){
            ans.push_back(tmp);
            return;
        }
        
        for(char x : mp[(digits[i] - '0')])
            solve(digits, tmp + x, i + 1, n);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {}; 
        solve(digits, "", 0, digits.size());
        return ans;
    }
};