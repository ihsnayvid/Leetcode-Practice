class Solution {
public:
    
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n & 1) return {};
        
        unordered_map<int, int> mp;
        sort(changed.rbegin(), changed.rend());
        vector<int> ans;
         
        for(auto i: changed){ 
            if(mp[2*i] > 0){
                ans.push_back(i);
                mp[2*i] --;
            }
            else mp[i]++;            
        }
        if(ans.size() == n/2)
            return ans;
        return {};
    }
};