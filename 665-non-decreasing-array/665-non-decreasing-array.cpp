class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3) return true;
        int c = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] >= nums[i-1]) continue;
            else{
                c++;
                if(c>1) return false;
                else if(i == 1 or nums[i] >= nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return true;
    }
};