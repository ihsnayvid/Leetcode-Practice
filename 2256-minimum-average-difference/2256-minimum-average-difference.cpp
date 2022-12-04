class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        long long pre = 0, suf = 0, ans = INT_MAX;
        int idx = -1;
        long long sum = 0;
        for(auto i: nums) sum += i;
        for(int i=0; i<n; i++){
            pre += nums[i];
            suf = sum - pre;
            long long leftavg = pre, rightavg = suf;
            leftavg /= (i+1);
            rightavg = (i == n-1) ? 0 : rightavg / (n-i-1);
            int diff = int(abs(leftavg - rightavg));
            
            if(diff < ans){
                ans = diff;
                idx = i;
            }
        }
        return idx;
    }
};