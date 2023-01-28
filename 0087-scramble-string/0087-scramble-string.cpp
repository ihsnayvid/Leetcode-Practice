class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string a, string b){
        int n = a.size();
        if(a == b) return true;
        if(n <= 1) return false;
        string key = a + "|" + b;
        if(mp.find(key) != mp.end()) return mp[key];
        
        for(int i=1; i<n; i++){
            bool noSwap = solve(a.substr(0, i), b.substr(0, i)) and solve(a.substr(i, n-i), b.substr(i, n-i));
            bool swap = solve(a.substr(0, i), b.substr(n-i, i)) and solve(a.substr(i, n-i), b.substr(0, n-i));
            
            if(noSwap or swap)
                return mp[key] = true;
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};