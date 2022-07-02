class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, mx = INT_MIN;
        for(auto i:nums){
            curr = max(i, curr + i);
            mx = max(mx, curr);
        }
        return mx;
    }
};