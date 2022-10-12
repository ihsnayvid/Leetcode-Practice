class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n-1, j = n-2, k = n-3;
        while(k >= 0){
            if(nums[i] < (nums[j] + nums[k]))
                return nums[i] + nums[j] + nums[k]; 
            i--, j--, k--;
        }
        return 0;
    }
};