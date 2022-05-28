class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        
        for(int i = 0; i <= n; i++)
            if(mp[i] < 1) return i;
        
        return 0;
    }
};