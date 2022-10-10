class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = -1;
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] > mn) l = i;
            mn = min(nums[i],mn);
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] < mx) r = i;
            mx = max(nums[i],mx);
        }
        
        return r - l + 1;
        
    }
};