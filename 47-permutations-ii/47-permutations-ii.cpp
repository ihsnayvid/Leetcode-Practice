class Solution {
public:
    
    void solve(int idx, int n , vector<int> nums, vector<vector<int>> &ans){
        if(idx == n) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            if(i != idx and nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            solve(idx+1, n, nums, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(0, nums.size(), nums, ans);
        return ans;
    }
};