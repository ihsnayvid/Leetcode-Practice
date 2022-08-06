class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto i: time){
            
            int k = i % 60; 
            ans += mp[(60 - k) % 60];
            mp[k]++;
            
        }
        return ans;
    }
};