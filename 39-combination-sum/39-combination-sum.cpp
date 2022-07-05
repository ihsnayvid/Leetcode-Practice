class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int> &ds, int t, vector<int> &arr, int n){
        if(ind == n){
            if(t == 0)
                ans.push_back(ds);
            return;
        }
        
        if(t >= arr[ind]){
            ds.push_back(arr[ind]);
            solve(ind,ds,t - arr[ind],arr,n);
            ds.pop_back();
        }
        solve(ind+1,ds,t,arr,n);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        int n = candidates.size();
        solve(0,ds,target,candidates,n);
        return ans;
    }
};