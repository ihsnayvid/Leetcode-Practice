class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0]) return 0;
        
        int l = 0, h = nums.size() - 1;
        int ans=0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        
        return ans+1;
    }
};