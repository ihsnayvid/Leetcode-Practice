class Solution {
public:
    void solve(int idx, int n, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        if(idx == n){
            ans.push_back(ds);
            return;
        }
        solve(idx+1, n, nums, ds, ans);
        ds.push_back(nums[idx]);
        solve(idx+1, n, nums, ds, ans);
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, n, nums, ds, ans);
        return ans;
    }
};