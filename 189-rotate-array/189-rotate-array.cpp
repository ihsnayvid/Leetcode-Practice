class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        k = k % n;
        if(k == 0 or n == 1) return;
        k = n - k;
        vector<int> ans(n);
        while(i<n){
            ans[i] = nums[k];
            k = (k + 1) % n;
            i++;
        }
        nums = ans;    
    }
};