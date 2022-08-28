class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int> &v, vector<int> &ds, int n, int idx, int &k){
        
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<n; i++){
            if(v[i] != -1){
                int x = v[i];
                ds.push_back(x);
                v[i] = -1;
                solve(v,ds,n,i+1,k);
                ds.pop_back();
                v[i] = x;
            }
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v(n);
        for(int i=0; i<n; i++)
            v[i] = i+1;
        
        vector<int> ds;
        solve(v, ds, n, 0, k);
        return ans;
    }
};