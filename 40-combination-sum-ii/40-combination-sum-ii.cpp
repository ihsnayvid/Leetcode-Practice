class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int> &arr, vector<int> &ds, int n, int target){
        if(target == 0)
            ans.push_back(ds);
        
        for(int i=ind; i<n ; i++){
            if(i>ind and arr[i] == arr[i-1]) continue;
            
            if(target < arr[i]) break;
            ds.push_back(arr[i]);
            solve(i+1, arr, ds, n, target - arr[i]);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        int n = candidates.size();        
        sort(candidates.begin(),candidates.end());
        solve(0, candidates, ds, n, target);
        
        return ans;
    }
};