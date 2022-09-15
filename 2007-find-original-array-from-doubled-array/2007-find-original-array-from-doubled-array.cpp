class Solution {
public:
    
    
    vector<int> findOriginalArray(vector<int>& changed) {
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
        
        for(auto i: mp){
            if(i.second != 0) return {};
        }
        return ans;
    }
};