class Solution {
public:
    
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n & 1) return {};
        
        unordered_map<int, int> mp;
        sort(changed.rbegin(), changed.rend());
        vector<int> ans;
         
        for(auto i: changed){ 
            if(mp[i<<1] > 0){
                ans.push_back(i);
                mp[i<<1] --;
            }
            else mp[i]++;            
        }
        if(ans.size() == (n>>1))
            return ans;
        return {};
    }
};