class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 1, right = 1, mx = nums[0], n =nums.size();
        for(int i=0; i<n; i++){
            left = (left ? left : 1) * nums[i];
            right = (right ? right : 1) * nums[n-i-1];
            mx = max(mx, max(left, right));
        }
        return mx;
    }
};