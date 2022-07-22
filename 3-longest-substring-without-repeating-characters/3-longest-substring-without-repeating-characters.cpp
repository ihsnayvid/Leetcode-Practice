class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i = 0, j = 0, n = s.length(), ans = 0;
        while(j<n){
            if(mp[s[j]] == 1){
                mp[s[i]] --;
                i++;
            }
            else{
                mp[s[j]]++;
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};