class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;
        int rep = 0, mis = 0;
        for(int i=1; i<=nums.size(); i++){
            if(mp[i] == 2) rep = i;
            if(mp[i] == 0) mis = i;
        }
        return {rep, mis};
    }
};