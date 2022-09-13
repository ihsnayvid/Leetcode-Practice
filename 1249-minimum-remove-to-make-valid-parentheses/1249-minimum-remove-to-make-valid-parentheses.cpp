class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        
        int count = 0;
        for(char i: s){
            if(i == '(') count ++;
            if(i != ')'){
                ans += i;
            }
            else{
                if(count > 0){
                    ans += i;
                    count--;
                }
            }
        }
        s = ans;
        ans = "";
        count = 0;
        reverse(s.begin(), s.end());
        for(char i: s){
            if(i == ')') count ++;
            if(i != '('){
                ans += i;
            }
            else{
                if(count > 0){
                    ans += i;
                    count--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};