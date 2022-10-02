class Solution {
public:
    
    void solve(string &s, int st, int en, int n, vector<string> &ds){
        if(st < en) return;
        if(st == n and en == n){
            ds.push_back(s);
            return;
        }
        s += "(";
        if(st < n) solve(s, st + 1, en, n, ds);
        s.pop_back();
        
        s += ")";
        if(en < n) solve(s , st, en + 1, n, ds);
        s.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ds;
        string s = "";
        solve(s, 0, 0, n, ds);
        return ds;
    }
};