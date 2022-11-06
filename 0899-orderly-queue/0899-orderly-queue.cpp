class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string temp = s,ans = s;
        do{
            s = s.substr(1) + s[0];
            if(s < ans) ans = s;
        }while(temp != s);
        return ans;
    }
};