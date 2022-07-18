class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int ans = 0;
        vector<int> pref(nums.size(),0);
        pref[0] = nums[0];
        mp[nums[0]]++;
        if(nums[0] == k) ans++;
        for(int i=1; i<nums.size(); i++){
            pref[i] = pref[i-1] + nums[i];
            if(pref[i] == k) ans++;
            if(mp.find(pref[i] - k) != mp.end())
                ans += mp[pref[i] - k];
            
            mp[pref[i]]++;
        }
        
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        for(int row = 0; row < n; row++){
            vector<int> v(m,0);
            for(int cur = row; cur < n; cur++){
                for(int j = 0; j < m; j++)
                    v[j] += matrix[cur][j];
                ans += subarraySum(v, target);
            }
        }
        
        return ans;
    }
};