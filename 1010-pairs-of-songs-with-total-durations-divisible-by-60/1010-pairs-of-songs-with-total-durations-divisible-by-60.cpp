class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto i: time){
            
            int k = i % 60;            
            int x = 60 - k;
            if(k == 0) ans += mp[0];
            else ans += mp[x];            
            mp[k]++;
            
        }
        return ans;
    }
};