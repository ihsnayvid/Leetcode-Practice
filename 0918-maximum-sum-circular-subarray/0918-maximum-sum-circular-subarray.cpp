class Solution {
public:
    int kadane(vector<int> arr){
        int curr = 0, mx = INT_MIN;
        for(auto i:arr){
            curr = max(i, curr + i);
            mx = max(mx, curr);
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int nonWrapSum = kadane(nums);
        int totalSum = 0, wrapSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
            nums[i] = -nums[i];
        }
        wrapSum = totalSum + kadane(nums);
        if(wrapSum == 0) return nonWrapSum;
        return max(wrapSum, nonWrapSum);
    }
};