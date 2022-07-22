class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i = 0, j = 0, n = s.length(), ans = 0;
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                int oldidx = i, newidx = mp[s[j]];
                ans = max(ans, j-i);
                i = newidx + 1;
                
                for(int k=oldidx; k<=newidx; k++)
                    mp.erase(s[k]);
            }            
            mp[s[j]] = j;
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};