class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        int odd = 0, even = 0, single = 0;
        for(string s : words) {
            mp[s]++;
        }
        
        for(auto i : mp) {
            string s = i.first;
            string r = "";
            r += s[1];
            r += s[0];
            if(s[0] != s[1] and mp[r]) {
                odd += min(mp[s], mp[r]);
            }
            if(s[0] == s[1]) {
                if(mp[s] == 1)  single = 1;
                else if(mp[s] > 1) {
                    even += i.second/2;
                    if(i.second % 2 == 1)   single = 1;
                }
            }
        }
        // cout << odd << " " << even << " " << single;
        int res = odd;
        res += even*2;
        res += single;
        return res*2;
    }
};