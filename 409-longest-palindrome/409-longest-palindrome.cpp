class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int even = 0, odd = 0;
        for(auto i: s)
            mp[i]++;
        for(auto i: mp){
            even += i.second / 2;
            odd += i.second % 2;
        }
        even = even * 2;
        if(odd)
            even ++;
        
        return even;
    }
};