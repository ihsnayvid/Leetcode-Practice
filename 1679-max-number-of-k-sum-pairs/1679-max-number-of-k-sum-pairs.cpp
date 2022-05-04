class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;
        
        for(int i = 0; i < nums.size(); i++) {
            if(mp[k-nums[i]] > 0){
                ans++;
                mp[nums[i]]--;
                mp[k-nums[i]]--;
                if(mp[nums[i]] < 0) ans--;                
            }
        }
        
        return ans;
    }
};