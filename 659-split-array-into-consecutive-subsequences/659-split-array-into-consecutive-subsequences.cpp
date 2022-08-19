class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp, nxt;
        for(auto i: nums) mp[i]++;
        
        for(auto i: nums){
            if(mp[i] == 0) continue;
            
            if(nxt[i] > 0)
                nxt[i] -- , mp[i] --, nxt[i+1]++;
            else if(mp[i] > 0 and mp[i+1] > 0 and mp[i+2] > 0)
                mp[i] --, mp[i+1] --, mp[i+2] --, nxt[i+3]++;
            else 
                return false;
        }
        return true;
    }
};