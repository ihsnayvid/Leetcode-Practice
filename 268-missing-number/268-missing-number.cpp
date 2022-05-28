class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, actual = (n * (n+1)) >> 1;
        for(auto i : nums) sum += i;
        
        return actual - sum;
    }
};