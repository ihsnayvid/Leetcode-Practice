class Solution {
public:
    vector<string> ans;
    
    void solve(string &s, string &ds, int idx, int n){
        if(ds.length() == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<n; i++){
            if(isdigit(s[i])){
                ds.push_back(s[i]);
                solve(s,ds,i+1,n);
                ds.pop_back();
            }
            else{
                char c = s[i];
                
                if(islower(s[i])){
                    ds.push_back(toupper(c));
                    solve(s,ds,i+1,n);
                    ds.pop_back();
                }
                else{
                    ds.push_back(tolower(c));
                    solve(s,ds,i+1,n);
                    ds.pop_back();
                }
                ds.push_back(c);
                solve(s,ds,i+1,n);
                ds.pop_back();
            }        
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        string ds = "";
        solve(s,ds,0,s.length());
        return ans;
    }
};