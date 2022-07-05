class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int> &ds, vector<int> &arr, int n){
        ans.push_back(ds);
        for(int i=ind; i<n; i++){
            if(i!=ind and arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            solve(i+1,ds, arr, n);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        solve(0,ds,nums,nums.size());
        return ans;
    }
};