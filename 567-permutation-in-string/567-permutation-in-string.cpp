class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        map<char,int> mp;
        for(auto s: s1)
            mp[s]++;
        
        int i = 0, j = 0;
        
        map<char,int> mpp;
        while(j<s2.length()){
            if(j-i+1 == k){ 
                mpp[s2[j]]++;            
                j++;
                if(mpp == mp) return true;
                mpp[s2[i]]--;
                if(mpp[s2[i]] == 0) mpp.erase(s2[i]);
                i++;
            }
            else {
                mpp[s2[j]]++;            
                j++;
            }
            // cout<<"\nmp---";
            // for(auto x: mp) cout<<x.first<<":"<<x.second<<" "; 
            // cout<<"\nmpp---";
            // for(auto x: mpp) cout<<x.first<<":"<<x.second<<" ";            

        }
        
        return false;
    }
};