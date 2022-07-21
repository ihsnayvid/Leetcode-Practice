class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //i tracks next 0 j tracks next non zero
        
        int i = 0, j = 0, n = nums.size();
        while(i<n){
           while(j<n and nums[j] == 0) j++;
            if(j>=n) break;
            swap(nums[i],nums[j]);
            i++, j++;
        }
    }
};