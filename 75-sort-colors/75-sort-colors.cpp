class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3] = {0};
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]]++;
        
        int k = 0;
        while(freq[0]--)
            nums[k++] = 0;
        while(freq[1]--)
            nums[k++] = 1;
        while(freq[2]--)
            nums[k++] = 2;
    
    }
};