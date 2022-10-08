class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, sum = 0, ans = 0, currdiff = 0;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            int j = i+1, k = n-1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                if(sum == target) return sum;
                else if (sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};