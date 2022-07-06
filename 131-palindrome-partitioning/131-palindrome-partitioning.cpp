class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string s){
        int i=0, j = s.length()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind, vector<string> &ds, string s){
        if(ind == s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<s.length(); i++){
            string sub = s.substr(ind,i-ind+1);
            if(isPal(sub)){
                ds.push_back(sub);
                solve(i+1,ds,s);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        solve(0,ds,s);
        return ans;
    }
};