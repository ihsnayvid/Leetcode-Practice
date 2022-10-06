class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        int ans = 0, c = 0;
        for(int i=0; i<n-2; i++){
            if(2 * (nums[i+1]) == (nums[i] + nums[i+2]))    //i, i+1, i+2 in AP
                c++; 
            else {
                ans += (c * (c+1)) / 2;     //taking every combination till i-1 
                c = 0;                      //subarrays of size 3, 4, 5 and so on 
            }
        }
        if(c) ans += (c * (c+1)) / 2;   //if still diff remains
        return ans;
    }
};