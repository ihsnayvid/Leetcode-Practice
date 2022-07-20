class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int idx, vector<int> &ds, int t, vector<int> &v, int n){
        if(idx == n){
            if(t == 0)
                ans.push_back(ds);
            return;
        }
        
        if(t < 0) return;
        ds.push_back(v[idx]);
        solve(idx, ds, t - v[idx],v, n);
        ds.pop_back();
        solve(idx+1, ds, t,v, n);
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        int n = candidates.size();
        solve(0,ds,target,candidates,n);
        return ans;
    }
};