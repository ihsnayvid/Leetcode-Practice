class Solution {
public:
    
    // 1 2 3 4 5 4 4 5
               
    // 1 2 3 4 5
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n == 1) return 1;
        int i = 0, j= 1;
        while(j<n){
            if(nums[i] == nums[j]) j++;
            else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
};