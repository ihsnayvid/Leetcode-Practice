class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i = 0, j = 0, curr = 0, mx = INT_MIN;
        while(j<s.length()){
            mp[s[j]]++;
            curr = max(curr, mp[s[j]]);
            while(j-i+1 - curr > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            mx = max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};