class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();           
        int ans = 0;        
        for(int i=0; i<n/2; i++)
            ans += abs(nums[i] - nums[n-1-i]);
        return ans;
    }
};