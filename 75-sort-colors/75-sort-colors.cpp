class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), st = 0, en = n-1;
        int i = 0;
        while(i<=en){
            if(nums[i] == 0){
                swap(nums[st], nums[i]);
                st++;
                i++;
            } 
                
            else if(nums[i] == 2){
                swap(nums[en], nums[i]);
                en--;
            }                
            else i++;
        }
    }
};