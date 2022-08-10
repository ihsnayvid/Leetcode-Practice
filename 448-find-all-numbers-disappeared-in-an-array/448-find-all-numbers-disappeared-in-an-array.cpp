class Solution {
public:
    //0 1 2 3 4 5 6 7 
    //4 3 2 7 8 2 3 1
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i<nums.size(); i++){
            int pos = abs(nums[i]) - 1;
            if(nums[pos] > 0)
                nums[pos] = -nums[pos];
        }
        
        for(int i=0; i<nums.size(); i++)
            if(nums[i] > 0) ans.push_back(i+1);
        
        return ans;
    }
};