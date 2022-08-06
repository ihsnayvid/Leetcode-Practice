class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int st = j+1, en = n-1;
                while(st < en){
                    long long sum = (long long)nums[st] + nums[en] + nums[j] + nums[i];
                    if(sum == target) {
                        ans.push_back({nums[st], nums[en], nums[i], nums[j]});
                        while(st+1 < n and nums[st] == nums[st+1]) st++;
                        while(en-1 >=0 and nums[en] == nums[en-1]) en--;
                        st ++, en --;
                    }
                    else if(sum < target) st ++;
                    else en --;
                }
                while(j+1 < n and nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n and nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};