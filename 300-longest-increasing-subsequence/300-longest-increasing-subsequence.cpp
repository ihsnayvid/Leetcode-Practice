class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size(), INT_MAX);
        int n = nums.size(), ans = 1;
        for(auto i: nums){
            int it = lower_bound(v.begin(), v.end(), i) - v.begin();
            v[it] = i;
            ans = max(ans, it + 1);
        }
        return ans;
    }
};