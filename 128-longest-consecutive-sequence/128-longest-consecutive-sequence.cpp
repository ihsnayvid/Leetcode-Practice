class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = size(nums);
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        
        int ans = INT_MIN, l = 1;
        for(auto i: nums){
            if(mp.find(i-1) != mp.end()) continue;
            int x = i;
            while(mp.find(x+1) != mp.end()){
                l++;
                x++;
            }
            ans = max(ans, l);
            l = 1;            
        }
        return ans;
    }
};