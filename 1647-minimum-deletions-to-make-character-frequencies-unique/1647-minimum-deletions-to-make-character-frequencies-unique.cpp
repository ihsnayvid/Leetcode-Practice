class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;
        
        int ans = 0;
        set<int> freq;
        for(auto i:mp){
            while(freq.count(i.second)>0){
                i.second--;
                ans++;
            }
            if(i.second > 0) freq.insert(i.second);
        }
        
        return ans;
    }
};