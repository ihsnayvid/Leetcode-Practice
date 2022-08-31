class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = INT_MIN, count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0) maj = nums[i];
            count += (nums[i] == maj) ? 1 : -1;
        }
        return maj;
    }
};