class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        unordered_map<char,int> mp;
        for(auto s: s1)
            mp[s]++;
        
        int i = 0, j = 0;
        
        unordered_map<char,int> mpp;
        while(j<s2.length()){
            mpp[s2[j]]++;
            if(j-i+1 == k){ 
                if(mpp == mp) return true;
                mpp[s2[i]]--;
                if(mpp[s2[i]] == 0) mpp.erase(s2[i]);
                i++;
            }
            j++;
        }
        
        return false;
    }
};