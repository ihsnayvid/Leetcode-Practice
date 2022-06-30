class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int med;
        if(n&1) med = nums[n/2];
        else med = (nums[n/2] + nums[n/2 - 1])/2;
        
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += abs(med - nums[i]);
        return ans;
    }
};