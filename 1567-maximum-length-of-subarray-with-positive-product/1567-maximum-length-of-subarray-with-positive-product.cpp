class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int l = 0, r = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                l = 0, r = 0;
                continue;
            }
            
            l++;
            r = (r > 0 ? r+1 : 0);
            if(nums[i] < 0){
                int t = l;
                l = r;
                r = t;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};