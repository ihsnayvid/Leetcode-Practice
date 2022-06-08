class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> arr, vector<int> &ds, int n, int sum, int target){
        if(sum == target){
            // for(auto x: ds) cout<<x<<" ";
            // cout<<endl;
            ans.push_back(ds);
        }
        if(sum > target) return;
        
        for(int j=i; j<n; j++){
            if(j != i and arr[j] == arr[j-1]) continue;
            
            if(arr[j] > target) break;
            ds.push_back(arr[j]);
            solve(j+1, arr, ds, n, sum + arr[j], target);
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        int n = candidates.size();
        
        sort(candidates.begin(),candidates.end());
        solve(0, candidates, ds, n, 0, target);
        
        return ans;
    }
};