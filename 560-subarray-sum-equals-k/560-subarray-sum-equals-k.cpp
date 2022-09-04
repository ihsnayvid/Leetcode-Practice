class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0;
        
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        mp[prefix[0]]++;
        if(prefix[0] == k) ans ++;
        
        
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
            if(prefix[i] == k) ans++;
            if(mp.find(prefix[i] - k) != mp.end())
                ans += mp[prefix[i] - k];
            mp[prefix[i]] ++;
        }
        return ans;
    }
};