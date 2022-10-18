class Solution {
public:
    string say(string s){
        string ans = "";
        int count = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) count ++;
            else{
                ans += to_string(count);
                ans += s[i-1];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += s.back();
        return ans;
    }
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            s = say(s);
        }
        return s;
    }
};