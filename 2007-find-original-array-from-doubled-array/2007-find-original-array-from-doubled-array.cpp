class Solution {
public:
    
    
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        
        unordered_map<int, int> mp;
        sort(changed.rbegin(), changed.rend());
        vector<int> ans;
        
        // 8 6 4 3 2 1
        // 
        for(auto i: changed){           
            
            if(mp[2*i] > 0){
                ans.push_back(i);

                mp[2*i] --;
                if(mp[2*i] <= 0) mp.erase(2*i);
            }
            else mp[i]++;            
        }
        
        // if(!mp.size()) return ans;
        // return {};
        // // return ans;
        
        for(auto i: mp){
            if(i.second != 0) return {};
        }
        return ans;
    }
};