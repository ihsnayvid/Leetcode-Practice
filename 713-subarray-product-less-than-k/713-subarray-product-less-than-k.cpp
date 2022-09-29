class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 2) return 0;
        int i = 0, j = 0, ans = 0, curr = 1;
        while(j < nums.size()){
            curr *= nums[j];
            while(curr >=k){
                curr /= nums[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};