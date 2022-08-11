class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        for(int i=n-2; i>=0; i--){
            jumps++;
            if(nums[i] >= jumps)
                jumps = 0;
        }
        return !jumps;
    }
};