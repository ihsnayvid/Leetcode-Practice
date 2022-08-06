class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> mp;
//         for(auto i: time)
//             mp[i%60] ++;
        
//         for(auto i: mp){
           
//             if(i.first == 0) ans += i.second;
//             else if(i.second > 0 and i.first != 30 and mp[60-i.first] > 0){
//                 ans += i.second * mp[60-i.first];
//                 mp[60 - i.first] = 0;
//             }
            
//         }
        
//         int n = mp[30];
//         ans += n * (n-1) / 2;
        
        for(auto i: time){
            int k = i%60;
            
            int x = 60-k;
            if(k == 0) ans += mp[0];
            if(mp[x] > 0) ans += mp[x];
            
            mp[k]++;
        }
        return ans;
    }
};