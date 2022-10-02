class Solution {
public:
    
    void solve(string s, int st, int en, int n, vector<string> &ds){
        if(st < en) return;
        if(st == n and en == n){
            ds.push_back(s);
            return;
        }
        if(st < n) solve(s + "(", st + 1, en, n, ds);
        if(en < n) solve(s + ")", st, en + 1, n, ds);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ds;
        solve("", 0, 0, n, ds);
        return ds;
    }
};